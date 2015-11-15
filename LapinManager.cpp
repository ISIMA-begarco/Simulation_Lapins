#include "LapinManager.h"

using namespace std;

LapinManager::LapinManager(std::string p_str) :
    m_graine(p_str.begin(), p_str.end()), m_generateur(m_graine),
    m_mois(0), m_males(180,ClasseLapins(&m_generateur)), m_femelles(180,ClasseLapins(&m_generateur)) {  // 15 * 12

	m_males[12].nombre(1);
	m_femelles[12].nombre(1);

	for(int i = 0 ; i < 9 ; ++i) {
		m_males[i].tauxDeSurvie(pow(0.2,((double)1/12)));
		m_femelles[i].tauxDeSurvie(pow(0.2,((double)1/12)));
	}
	for(int i = 132 ; i < 180 ; ++i) {    // 11*12 = 11 ans = 132 mois
		m_males[i].tauxDeSurvie(pow(0.4-0.1*((int)(i-132)/12), ((double)1/12)));
		m_femelles[i].tauxDeSurvie(pow(0.4-0.1*((int)(i-132)/12),((double)1/12)));
	}
}

LapinManager::~LapinManager() {

}

void LapinManager::simulation(unsigned long long p_duree) {
    unsigned long long      population = 0;
    for(m_mois = 0 ; m_mois < p_duree ; ++m_mois) {
        /// mort veillissement
        unsigned long long      nouvelEffectifMale      = 0,
                                nouvelEffectifFemelle   = 0;
        population = 0;
        for(unsigned i = 0 ; i < m_males.size() ; ++i) {
            population += (nouvelEffectifMale + nouvelEffectifFemelle);
            nouvelEffectifMale = m_males[i].vieillissement(nouvelEffectifMale);
            nouvelEffectifFemelle = m_femelles[i].vieillissement(nouvelEffectifFemelle);
        }

        /// naissances
        unsigned long long      naissances = 0,
                                males = 0;

        for(unsigned i = 9 ; i < m_femelles.size() ; ++i) {         // nombre de naissances le mois
            naissances += m_femelles[i].reproduction(m_mois%12);
        }
        /// determination du sexe
        if(naissances >= 100) {           // traitement pour grand nombre de naissance
            std::normal_distribution<double> normale(0.5*naissances,
                                             sqrt(0.25*naissances));
            males = round(normale(m_generateur));
        } else {                        // traitement individuel
            for(unsigned i = 0 ; i < naissances ; ++i) {
                std::bernoulli_distribution bernoulli(0.5);
                males += (bernoulli(m_generateur) ? 1 : 0);
            }
        }
        m_males[0].nombre(males);
        m_femelles[0].nombre(naissances-males);
        population += naissances;


        cout << "[ " << (m_mois%12)+1 << "/" << 2000+(m_mois/12) << " ] Taille de la population : " << population << endl;
        cout << "Nombre de naissances : " << naissances << endl;
    }
}

