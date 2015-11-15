#include <iostream>

#include "LapinManager.h"
#include <cmath>

using namespace std;

int main(int, char **) {
    LapinManager laps;

    laps.simulation(10 * 12, true);

	return 0;
}

