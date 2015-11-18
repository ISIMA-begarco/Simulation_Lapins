/**
 *
 *	\file 		LapinManager.h
 *	\brief 		Simulateur de population de lapins.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Simulateur de population de lapins à partir d'un couple de un an
 *
 */

#ifndef _LAPINMANAGER_H_
#define _LAPINMANAGER_H_

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include "ClasseLapins.h"

///	Definition du type de comptage
typedef		long double     INTEGER;

/**
 *
 *	\class		LapinManager
 *	\brief		Classe de simulation de population de lapins.
 *
 *	Simulateur de population de lapins à partir d'un couple de un an.
 *
 */
class LapinManager {
	protected:
	    /// Graine du generateur aleatoire
	    std::seed_seq                   m_graine;
	    ///	Generateur aleatoire Mersenne Twister
        std::mt19937                    m_generateur;
        ///	Mois en cours
		unsigned long long				m_mois;
		///	Vecteur des classes d'ages de lapins males
		std::vector<ClasseLapins>		m_males,
		/// Vecteur des classes d'ages de lapins femelles
										m_femelles;
        /// Fichier de sortie
		std::ofstream					m_file;

	public:
		/**
 		 *	\brief		Constructeur de la classe LapinManager.
 		 *	\param		p_str : chaîne d'initiallisation du generateur MT, valeur par defaut -> "Les lapins c'est mieux en civet."
 		 */
		LapinManager(std::string = "Les lapins c'est mieux en civet.");
		/**
 		 *	\brief		Destructeur de la classe LapinManager.
 		 */
		virtual ~LapinManager();
		/**
 		 *	\brief		Simulation mensuelle de la population de lapins.
 		 *	\fn			INTEGER simulation(unsigned long long p_mois = 120, bool p_affichage = false, bool p_fileOut = true);
 		 *	\param		p_mois : entier representant le nombre de mois de simulation
 		 *	\param		p_affichage : booleen vrai alors sortie console activee sinon silencieux
 		 *	\param		p_affichage : booleen vrai alors sortie dans un fichier lap.out activee sinon rien
 		 *	\return		Nombre de lapins dans la population en fin de simulation.
 		 */
 		INTEGER simulation(unsigned long long = 120, bool = false, bool = true);
		/**
 		 *	\brief		Remise a zero de la simulation.
 		 *	\fn			void reset()
 		 */
		void reset();
		/**
 		 *	\brief		Ecrit un nombre dans le fichier
 		 *	\fn			void write(long double p_number)
 		 *  \param      p_number : nombre a ecrire
 		 */
		void write(long double);
};

#endif
