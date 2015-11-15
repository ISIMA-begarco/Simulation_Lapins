#ifndef _LAPINMANAGER_H_
#define _LAPINMANAGER_H_

#include <vector>
#include <random>
#include <iostream>
#include "Lapin.h"

class LapinManager {
	protected:
	    std::seed_seq                   m_graine;
        std::mt19937                    m_generateur;
		unsigned long 					m_mois;
		std::vector<ClasseLapins>		m_males,
										m_femelles;

	public:
		LapinManager(std::string = "Les lapins c'est mieux en civet.");
		LapinManager(unsigned long long int);
		virtual ~LapinManager();

		unsigned long long simulation(unsigned long long = 120, bool = false);
};

#endif
