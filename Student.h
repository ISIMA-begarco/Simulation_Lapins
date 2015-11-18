/**
 *
 *	\file 		Student.cpp
 *	\brief 		Loi de Student.
 *	\author 	Benoit GARCON
 *  \author     Benjamin BARBESANGE
 *	\version 	1.0
 *	\date 		20 Novembre 2015
 *
 *	Permet d'utiliser la loi de Student.
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

/**
 *
 *	\class		Student
 *	\brief		Classe de la loi de Student.
 *
 *	Loi de Student pour les quantiles.
 *
 */
class Student {
    protected:
                    /// Valeurs de 1 a 30
        double    * values_,
                    /// Valeurs 30 a 40
                    coeff_40_30_,
                    /// Valeurs 30 a 40
                    off_40_30,
                    /// Valeurs 40 a 80
                    coeff_80_40_,
                    /// Valeurs 40 a 80
                    off_80_40,
                    /// Valeurs 80 a 120
                    coeff_120_80_,
                    /// Valeurs 80 a 120
                    off_120_80,
                    /// Valeurs a l'infini
                    infty_;

    public:
		/**
 		 *	\brief		Constructeur de la classe Student.
 		 */
        Student();
		/**
 		 *	\brief		Destructeur de la classe Student.
 		 */
        ~Student();
        /**
         *  \brief      Permet de recuperer le quantile pour n experiences.
         *  \fn         double getQuantile(int p_nbExp)
         *  \param      p_nbExp : entier donnant le nombre d'experiences
         *  \return     Double representant le quantile demande.
         */
        double getQuantile(int);
};

#endif // STUDENT_H
