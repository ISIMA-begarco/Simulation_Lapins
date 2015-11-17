#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>

#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "LapinManager.h"

using namespace std;

/** argv :	-v : verbose -> affiche a l'ecran
			-f : file -> sort dans un fichier lap.out
			first int : nombre d'annees d'un simulation
			sec int : nombre de simulations
**/

int main(int argc, char ** argv) {
    unsigned long long		years 			= 20,
							repl 			= 1;
    long double			  * res;
	bool					writeOnScreen	= false,
							writeInFile		= false;
    LapinManager 			laps;

/// Traitement des entrees en ligne de commande

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
		} else {
            std::string integer = argv[i];
			if(numberOfIntInInput==0) {
				istringstream(integer) >> years;
			} else if(numberOfIntInInput==1) {
				istringstream(integer) >> repl;
			}
			numberOfIntInInput++;
		}
	}

	res = new long double[repl];

	cout << "Arguments : annees = " << years << " et repetitions = " << repl << endl << endl;

/// Combien de lapins sur ? tirages sur ? annees

    for(unsigned long long i = 0; i < repl; i++) {
        res[i] = laps.simulation(years * 12, writeOnScreen, writeInFile);
        laps.reset();
    }

    // Affichage des resultats
    if(repl>1)
	    std::copy(res, res+repl, std::ostream_iterator<long double>(std::cout, "\n"));

	cout << endl;
	// Liberation de la memoire
	delete [] res;

	return 0;
}


/// Combien d'annees pour ? lapins en faisant ? replications
/*
    for(unsigned k = 0; k < 10; k++) {
        unsigned i = 0; res[0] = 0;
        while(res[0] < 1000000000 && i < 2000) {
            res[0] = laps.simulation(1 * 12, false);
            i++;
        }
        cout << i << endl;
        laps.reset();
    }
*/
