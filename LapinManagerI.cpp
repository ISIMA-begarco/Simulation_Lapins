/**
 *
 *	\file 		LapinManager.cpp
 *	\brief 		Simulateur de population de lapins.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Simulateur de population de lapins à partir d'un couple de un an
 *
 */

#include "LapinManagerI.h"

using namespace std;

LapinManager::LapinManager(std::string p_str) :
    m_graine(p_str.begin(), p_str.end()), m_generateur(m_graine),
    m_mois(0), m_males(180,ClasseLapins(&m_generateur)), m_femelles(180,ClasseLapins(&m_generateur)) {  // 15 * 12

	// ajout d'Adam et Eve ou bien Bob et Alice
	m_males[12].nombre(1);
	m_femelles[12].nombre(1);

	// initialisation des taux de survie "speciaux"
	for(int i = 0 ; i < 9 ; ++i) {
		m_males[i].tauxDeSurvie(pow(0.2,((double)1/12)));
		m_femelles[i].tauxDeSurvie(pow(0.2,((double)1/12)));
	}
	for(int i = 132 ; i < 180 ; ++i) {    // 11*12 = 11 ans = 132 mois
		m_males[i].tauxDeSurvie(pow(0.4-0.1*((int)(i-132)/12), ((double)1/12)));
		m_femelles[i].tauxDeSurvie(pow(0.4-0.1*((int)(i-132)/12),((double)1/12)));
	}
	// ouverture du fichier de sortie
	m_file.open ("lap.out", std::ofstream::out | std::ofstream::trunc);
}

LapinManager::~LapinManager() {
	// fermeture du fichier de sortie
	m_file.close();
}

INTEGER LapinManager::simulation(unsigned long long p_duree, bool p_print, bool p_outFile) { // p_print indique si on a affiche ou pas
    INTEGER					population = 0,									// Compteur de population totale
							dateStop = m_mois+p_duree;						// Date d'arret
	bool					writeInFile = m_file.is_open() && p_outFile;	// Booleen vrai alors ecriture dans un fichier
    for(/*m_mois*/ ; m_mois < dateStop ; ++m_mois) {	// pour chaque mois jusqu'a la date d'arret
        // mort veillissement
        INTEGER					nouvelEffectifMale      = 0,		// Nombre de males d'une classe survivant
                                nouvelEffectifFemelle   = 0,		// Nombre de femelles d'une classe survivant
                                males   				= 0,		//	Nombre de males total
                                femelles  	 			= 0,		// Nombre de femelles	total
								morts 					= 0;		// Nombre de morts mensuel
        bool                    presenceReproducteur    = false;    // Y a t il un male reproducteur
        population = 0;
        for(unsigned i = 0 ; i < m_males.size() ; ++i) {
			males += nouvelEffectifMale;
			femelles += nouvelEffectifFemelle;
            population += (nouvelEffectifMale + nouvelEffectifFemelle);
			morts += (m_males[i].nombre()+m_femelles[i].nombre());
            nouvelEffectifMale = m_males[i].vieillissement(nouvelEffectifMale);
            nouvelEffectifFemelle = m_femelles[i].vieillissement(nouvelEffectifFemelle);
			morts = morts - (nouvelEffectifMale+nouvelEffectifFemelle);
        }

        // naissances
        INTEGER					naissances  = 0,		// Nombre de naissances mensuel
                                bebeMales   = 0;		// Nombre de nouveaux nes males
        unsigned                inc         = 9;        // indice de parcours
        while(inc < 180 && !(presenceReproducteur=(m_males[inc++].nombre()!=0)));
        if(presenceReproducteur) {
            for(unsigned i = 9 ; i < m_femelles.size() ; ++i) {         // nombre de naissances le mois
                naissances += m_femelles[i].reproduction(m_mois%12);
            }
        }
        // determination du sexe
        if(naissances >= 100) {           // traitement pour grand nombre de naissance
            std::normal_distribution<long double>	normale(0.5*naissances,
                                                    sqrt(0.25*naissances));		// Loi normale
            bebeMales = round(normale(m_generateur));
        } else {                        // traitement individuel
            for(unsigned i = 0 ; i < naissances ; ++i) {
                std::bernoulli_distribution bernoulli(0.5);		// Loi Bernouilli
                bebeMales += (bernoulli(m_generateur) ? 1 : 0);
            }
        }
        m_males[0].nombre(bebeMales);
        m_femelles[0].nombre(naissances-bebeMales);
		males += m_males[0].nombre();
		femelles += m_femelles[0].nombre();
        population += naissances;

        if(p_print) {	// affichage console
        	cout << "[ " << (m_mois%12)+1 << "/" << 2000+(m_mois/12) << " ]\t--------------------------------" << endl;
			cout << "Nombre d'individus :\t" << population << endl;
        	cout << "Nombre de naissances :\t" << naissances << endl;
        	cout << "Nombre de morts :\t" << morts << endl;
        	cout << "Nombre de males :\t" << males << endl;
        	cout << "Nombre de femelles :\t" << femelles << endl;
        }
		if(writeInFile) {	// sortie fichier
			m_file << "[ " << (m_mois%12)+1 << "/" << 2000+(m_mois/12) << " ]\t" << population << "\t" << naissances << "\t" << morts << "\t" << males << "\t" << femelles << endl;
		}
    }
    m_file << endl;
    return population;
}

void LapinManager::reset() { // remise a zero pour refaire une simu
    m_mois = 0;
    // RAZ du nombre de lapins
    for(unsigned i = 0; i < m_males.size(); i++) {
        m_males[i].nombre(0);
        m_femelles[i].nombre(0);
    }

    // Ajout de 2 individus
    m_males[12].nombre(1);
    m_femelles[12].nombre(1);
}
