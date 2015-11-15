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

    laps.simulation(10 * 12, true);
    for(unsigned i = 0; i < repl; i++) {
        res[i] = laps.simulation(years * 12, false);
        laps.reset();
        //system("pause"); // attends qu'on appuies sur une touche
    }

    // Affichage des resultats
    std::copy(res, res+repl, std::ostream_iterator<unsigned>(std::cout, " - "));

	return 0;
}
