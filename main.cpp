#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>

#include <cmath>

#include "LapinManager.h"

using namespace std;

int main(int, char **) {
    unsigned years = 10, repl = 20;
    unsigned res[repl];
    LapinManager laps;

/// Combien de lapins sur ? tirages sur ? annees
/**
    laps.simulation(10 * 12, true);
    for(unsigned i = 0; i < repl; i++) {
        res[i] = laps.simulation(years * 12, false);
        laps.reset();
        //system("pause"); // attends qu'on appuies sur une touche
    }

    // Affichage des resultats
    std::copy(res, res+repl, std::ostream_iterator<unsigned>(std::cout, " - "));
*/

/// Combien d'annees pour ? lapins en faisant ? replications

    for(unsigned k = 0; k < 10; k++) {
        unsigned i = 0; res[0] = 0;
        while(res[0] < 1000000000 && i < 2000) {
            res[0] = laps.simulation(1 * 12, false);
            i++;
        }
        cout << i << endl;
        laps.reset();
    }

	return 0;
}
