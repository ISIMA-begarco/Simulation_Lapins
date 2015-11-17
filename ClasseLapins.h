/**
 *
 *	\file       ClasseLapins.h
 *	\brief      Classe statistique de lapins du meme age.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version    1.0
 *	\date       20 Novembre 2015
 *
 *	Classe statistique de lapins du meme age pouvant evoluer au fil du temps
 *
 */

#ifndef _CLASSELAPINS_H_
#define _CLASSELAPINS_H_

///	Definition du type de comptage
#define		INTEGER		long double

#include <random>
#include <iostream>

/**
 *
 *	\class      ClasseLapins
 *	\brief      Classe d'age de la population de lapins.
 *
 *	Represente une classe d'age (en mois) d'une population de lapins sans
 *	distinction de sexe. Peut evoluer indépendamment des autres classes.
 *
 */
class ClasseLapins {
	protected:
	    /// Nombre de lapins dans la classe
		INTEGER		     		m_nombre;
		///	Probabilite de survie mensuelle des lapins
		double					m_tauxDeSurvie;
		///	Generateur aleatoire Mersenne Twister
		std::mt19937          * m_generateur;

	public:
		/**
 		 *	\brief      Constructeur de la classe ClasseLapins.
 		 *	\param      p_generateur : pointeur vers le generateur MT choisi
 		 */
		ClasseLapins(std::mt19937 * p_generateur);
		/**
 		 *	\brief		Destructeur de la classe ClasseLapins.
 		 */
		virtual ~ClasseLapins();
		/**
 		 *	\brief		Modification du nombre de lapins.
 		 *	\fn			void nombre(const INTEGER & p_nombre)
 		 *	\param		p_nombre : nouveau nombre de lapins dans la classe
 		 */
		void nombre(const INTEGER &);
		/**
 		 *	\brief		Modification de la probabilite de survie des lapins.
 		 *	\fn			void tauxDeSurvie(const double & p_tauxDeSurvie)
 		 *	\param		p_tauxDeSurvie : nouveau taux de survie
 		 */
		void tauxDeSurvie(const double &);
		/**
 		 *	\brief		Acces au nombre de lapins.
 		 *	\fn			INTEGER nombre() const
 		 *	\return		Nombre de lapins dans la classe
 		 */
		INTEGER nombre() const;
		/**
 		 *	\brief		Acces aux chances de survie des lapins.
 		 *	\fn			double tauxDeSurvie() const
 		 *	\return		Probabilite de survie entre 0.0 et 1.0
 		 */
		double tauxDeSurvie() const;
		/**
 		 *	\brief		Simulation du vieillissement.
 		 *	\fn			INTEGER vieillissement(INTEGER p_nombre)
 		 *	\param		p_nombre : Nombre de lapins entrant dans la classe apres vieillissement
 		 *	\return		Nombre de lapins vieillissant d'un mois.
 		 */
		INTEGER vieillissement(INTEGER);
		/**
 		 *	\brief		Simulation de la reproduction.
 		 *	\fn			INTEGER reproduction(unsigned p_mois)
 		 /	\param		p_mois : numero du mois entre 0 et 11
 		 *	\return		Nombre de nouveaux nes de sexe indifferent
 		 */
		INTEGER reproduction(unsigned);
};

#endif
