/**************************************************************************
 *
 *	\file 		LapinManager.h
 *	\brief 		Simulateur de population de lapins.
 *	\author 	Benoit GARCON Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Simulateur de population de lapins à partir d'un couple de un an
 *	
 **************************************************************************/

#ifndef _LAPINMANAGER_H_
#define _LAPINMANAGER_H_

#define		INTEGER		unsigned long long		///	Definition du type de comptage

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include "ClasseLapinsI.h"

/**************************************************************************
 *
 *	\class		LapinManager
 *	\brief		Classe de simulation de population de lapins.
 *
 *	Simulateur de population de lapins à partir d'un couple de un an.
 *	
 **************************************************************************/
class LapinManager {
	protected:
	    std::seed_seq                   m_graine;		/// Graine du generateur aleatoire
        std::mt19937                    m_generateur;	///	Generateur aleatoire Mersenne Twister
		unsigned long long				m_mois;			///	Mois en cours
		std::vector<ClasseLapins>		m_males,		///	Vecteur des classes d'ages de lapins males
										m_femelles;		/// Vecteur des classes d'ages de lapins femelles
		std::ofstream					m_file;			/// Fichier de sorti

	public:
		/**************************************************************************
 		 *	\brief		Constructeur de la classe LapinManager.
 		 *	\param		p_str : chaîne d'initiallisation du generateur MT, valeur par defaut -> "Les lapins c'est mieux en civet."
 		 */
		LapinManager(std::string = "Les lapins c'est mieux en civet.");
		/**************************************************************************
 		 *	\brief		Destructeur de la classe LapinManager.
 		 */
		virtual ~LapinManager();
		/**************************************************************************
 		 *	\brief		Simulation mensuelle de la population de lapins.
 		 *	\fn			INTEGER simulation(unsigned long long p_mois = 120, bool p_affichage = false, bool p_fileOut = true);
 		 *	\param		p_mois : entier representant le nombre de mois de simulation
 		 *	\param		p_affichage : booleen vrai alors sortie console activee sinon silencieux
 		 *	\param		p_affichage : booleen vrai alors sortie dans un fichier lap.out activee sinon rien
 		 *	\return		Nombre de lapins dans la population en fin de simulation.
 		 */
 		INTEGER simulation(unsigned long long = 120, bool = false, bool = true);
		/**************************************************************************
 		 *	\brief		Remise a zero de la simulation.
 		 *	\fn			void reset()
 		 */
		void reset();
};

#endif
