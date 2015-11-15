#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>

#include "LapinManager.h"
#include <cmath>

using namespace std;

int main(int, char **) {
    unsigned years = 10, repl = 20;
    unsigned res[repl];
    LapinManager laps;

    for(unsigned i = 0; i < repl; i++) {
        res[i] = laps.simulation(years * 12, false);
        laps.reset();
        //system("pause"); // attends qu'on appuis sur une touche
    }

    // Affichage des résultats
    std::copy(res, res+repl, std::ostream_iterator<unsigned>(std::cout, " - "));

	return 0;
}

