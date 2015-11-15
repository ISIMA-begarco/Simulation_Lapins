#ifndef _CLASSELAPINS_H_
#define _CLASSELAPINS_H_

#include <random>
#include <iostream>

class ClasseLapins {
	protected:
		unsigned long			m_nombre;
		double					m_tauxDeSurvie;
		std::mt19937          * m_generateur;

	public:
		ClasseLapins(std::mt19937 *);
		virtual ~ClasseLapins();

		void nombre(const unsigned long long &);
		void tauxDeSurvie(const double &);
		const unsigned long nombre() const;
		const double tauxDeSurvie() const;

		unsigned long long vieillissement(unsigned long long);
		unsigned long long reproduction(unsigned);
};

#endif
