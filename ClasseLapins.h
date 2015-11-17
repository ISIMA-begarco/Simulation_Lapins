#ifndef _CLASSELAPINS_H_
#define _CLASSELAPINS_H_

#include <random>
#include <iostream>

class ClasseLapins {
	protected:
		long double     		m_nombre;
		double					m_tauxDeSurvie;
		std::mt19937          * m_generateur;

	public:
		ClasseLapins(std::mt19937 *);
		virtual ~ClasseLapins();

		void nombre(const long double &);
		void tauxDeSurvie(const double &);
		const long double nombre() const;
		const double tauxDeSurvie() const;

		long double vieillissement(long double);
		long double reproduction(unsigned);
};

#endif
