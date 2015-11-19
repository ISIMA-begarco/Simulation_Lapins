/**
 *
 *	\file       ClasseLapins.cpp
 *	\brief      Classe statistique de lapins du meme age.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version    1.0
 *	\date       20 Novembre 2015
 *
 *	Classe statistique de lapins du meme age pouvant evoluer au fil du temps
 *
 */

#include "ClasseLapinsI.h"

ClasseLapins::ClasseLapins(std::mt19937 * p_gen) : m_nombre(0), m_tauxDeSurvie(pow(0.5,((double)1/12))), m_generateur(p_gen) {

}

ClasseLapins::~ClasseLapins() {

}

void ClasseLapins::nombre(const INTEGER & p_nombre) {
	m_nombre = p_nombre;
}

void ClasseLapins::tauxDeSurvie(const double & p_tauxDeSurvie) {
	m_tauxDeSurvie = p_tauxDeSurvie;
}

INTEGER ClasseLapins::nombre() const {
	return m_nombre;
}

double ClasseLapins::tauxDeSurvie() const {
	return m_tauxDeSurvie;
}

INTEGER ClasseLapins::vieillissement(INTEGER p_nouvelEffectif) {
    std::normal_distribution<long double>  	normale(m_tauxDeSurvie*m_nombre,
                                            sqrt(m_tauxDeSurvie*m_nombre*(1-m_tauxDeSurvie)));	// Loi normale de survie
    std::bernoulli_distribution             bernoulli(m_tauxDeSurvie);	// Loi de Bernouilli de survie
    INTEGER									retour = 0;		// Nombre de survivants

    if(m_nombre >= 100) {           // traitement pour grande population
        retour = round(normale(*m_generateur));
    } else {                        // traitement individuel
        for(unsigned i = 0 ; i < m_nombre ; ++i) {
            retour += (bernoulli(*m_generateur) ? 1 : 0);
        }
    }
    m_nombre = p_nouvelEffectif;
    return retour;
}

INTEGER ClasseLapins::reproduction(unsigned p_mois) {
    float           probabilite_portee  = 0;		// Probabilite individuelle d'avoir une portee
    INTEGER			retour              = 0;		//	Nombre de nouveaux-nes
    if(p_mois > 0 && p_mois < 9) {      // si on est en periode de reproduction
        probabilite_portee = 0.5;
        if(p_mois > 2 && p_mois < 7) {  // si on est dans la haute periode
            probabilite_portee = 1;
        }
        if(m_nombre >= 100) {           // traitement pour grande population
            std::normal_distribution<long double>	normale(9/2*probabilite_portee*m_nombre,
                                                    sqrt(5/4*probabilite_portee*m_nombre));
            retour = round(normale(*m_generateur));
        } else {                        // traitement individuel
            std::bernoulli_distribution bernoulli(probabilite_portee);  // tirage d'existence d'une portee
            std::uniform_int_distribution<int> uniforme(3,6);       // tirage du nombre d'individu par portee
            for(unsigned i = 0 ; i < m_nombre ; ++i) {
                retour += (bernoulli(*m_generateur) ? uniforme(*m_generateur) : 0);
            }
        }
    }
    return retour;
}
