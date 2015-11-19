/**
 *
 *	\file 		main.cpp
 *	\brief 		Programme de simulation d'une population de lapins.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Programme de simulation stochastique d'une population de lapins
 *	a partir d'un couple d'un an.
 *
 */

#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>

#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "LapinManagerI.h"
#include "Student.h"

using namespace std;

///	Definition du type de comptage
typedef		unsigned long long     INTEGER;

/**
 *
 *	\fn int 	main(int argc, char ** argv)
 *	\brief 		Effectue une ou plusieurs simulations d'un certain nombre d'annees.
 *  \param 		option : -v pour le mode verbose et -f pour la sortie dans un fichier
 *	\param 		int_1 : entier donnant le nombre d'annees d'une simulation [facultatif]
 *	\param 		int_2 : entier donnant le nombre de simulations [facultatif]
 *  \return 	0
 *
 *	Programme principal utilisant des unsigned long long
 *
 */
int main(int argc, char ** argv) {
    unsigned long long		years 			= 10,		// Nombre d'annees de simulation
							repl 			= 1;		// Nombre de replication de la simulation
    vector<INTEGER>		    res;						// Tableau de resultats
	bool					writeOnScreen	= false,	// Booleen pour l'affichage
							writeInFile		= false;	// Booleen pour l'ecriture dans un fichier lap.out
    LapinManager 			laps;						// Objet de la simulation
    Student                 st;
	long double             esperance = 0.,
                            variance = 0.,
                            rayon = 0.;


	// Traitement des entrees en ligne de commande

	unsigned numberOfIntInInput = 0;
	for(int i = 1 ; i < argc ; i++) {
		if(argv[i][0]=='-') {	// on a au moins une option
			for(unsigned j = 1 ; j < strlen(argv[i]) ; ++j) {
				if(argv[i][j]=='v') {
					writeOnScreen = true;
				} else if(argv[i][j]=='f') {
					writeInFile = true;
				}
			}
		} else {	// recuperation des entiers
            std::string integer = argv[i];
			if(numberOfIntInInput==0) {
				istringstream(integer) >> years;
			} else if(numberOfIntInInput==1) {
				istringstream(integer) >> repl;
			}
			numberOfIntInInput++;
		}
	}


	// Boucle de simulation

    for(unsigned long long i = 0; i < repl; i++) {
        res.push_back(laps.simulation(years * 12, writeOnScreen, writeInFile));
        laps.reset();
    }


    // Calcul de stats

    for(unsigned i = 0 ; i < res.size() ; ++i) {
		esperance += res[i];
	}
	esperance /= res.size();
	for(unsigned int i = 0 ; i < res.size() ; ++i) {
		variance += (esperance - res.at(i))*(esperance - res.at(i));
	}
	variance /= (res.size()-1);

	rayon = st.getQuantile(res.size())*sqrt(variance/res.size());


    // Affichage des resultats

    cout << endl << "Resultats :" << endl;
	std::copy(res.begin(), res.end(), std::ostream_iterator<INTEGER>(std::cout, "\n"));
	cout << endl << "Esperance :\t\t\t" << esperance << endl;
	cout << "Variance :\t\t\t" << variance << endl;
	cout << "Intervalle de confiance :\t[";
    printf("%.2lf ; %.2lf]\n",
           esperance-rayon,
           esperance+rayon);

    // Ajout dans le fichier

    if(writeInFile) {
        laps.write(esperance);
        laps.write(variance);
        laps.write(esperance-rayon);
        laps.write(esperance+rayon);
    }

	return 0;
}

