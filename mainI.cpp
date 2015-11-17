/**************************************************************************
 *
 *	\file 		main.cpp
 *	\brief 		Programme de simulation d'une population de lapins.
 *	\author 	Benoit GARCON Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Programme de simulation stochastique d'une population de lapins
 *	a partir d'un couple d'un an.
 *	
 **************************************************************************/

#define		INTEGER		unsigned long long		///	Definition du type de comptage

#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>

#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "LapinManagerI.h"

using namespace std;

/**************************************************************************
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
 **************************************************************************/
int main(int argc, char ** argv) {
    unsigned long long		years 			= 20,		/// Nombre d'annees de simulation
							repl 			= 1;		/// Nombre de replication de la simulation
    INTEGER				  * res;						///	Tableau de resultats
	bool					writeOnScreen	= false,	/// Booleen pour l'affichage
							writeInFile		= false;	/// Booleen pour l'ecriture dans un fichier lap.out
    LapinManager 			laps;						/// Objet de la simulation


	/// Traitement des entrees en ligne de commande

	unsigned numberOfIntInInput = 0;
	for(int i = 1 ; i < argc ; i++) {
		if(argv[i][0]=='-') {	/// on a au moins une option
			for(unsigned j = 1 ; j < strlen(argv[i]) ; ++j) {
				if(argv[i][j]=='v') {
					writeOnScreen = true;
				} else if(argv[i][j]=='f') {
					writeInFile = true;
				}
			}
		} else {	/// recuperation des entiers
            std::string integer = argv[i];
			if(numberOfIntInInput==0) {
				istringstream(integer) >> years;
			} else if(numberOfIntInInput==1) {
				istringstream(integer) >> repl;
			}
			numberOfIntInInput++;
		}
	}

	res = new INTEGER[repl];	/// initialisation du tableau des resultats


	/// Boucle de simulation
    for(unsigned long long i = 0; i < repl; i++) {
        res[i] = laps.simulation(years * 12, writeOnScreen, writeInFile);
        laps.reset();
    }

    /// Affichage des resultats
    cout << endl << "Resultats :" << endl;
	std::copy(res, res+repl, std::ostream_iterator<INTEGER>(std::cout, "\n"));
	cout << endl;
	
	/// Liberation de la memoire
	delete [] res;

	return 0;
}

