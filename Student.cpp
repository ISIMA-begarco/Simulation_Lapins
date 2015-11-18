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

#include "Student.h"

Student::Student() {
    /* -------------------------------------------------------------------- */
    /* constructor  Genere une "table de Student" a alpha = 5%              */
    /*                                                                      */
    /* En entree: void                                                      */
    /*                                                                      */
    /* En sortie: void                                                      */
    /* -------------------------------------------------------------------- */
    // Tableau statique des 30 premieres valeurs
    values_ = new double[30];
    values_[0] = 12.706; values_[1] = 4.303; values_[2] = 3.182; values_[3] = 2.776; values_[4] = 2.571;
    values_[5] = 2.447; values_[6] = 2.365; values_[7] = 2.308; values_[8] = 2.262; values_[9] = 2.228;
    values_[10] = 2.201; values_[11] = 2.179; values_[12] = 2.160; values_[13] = 2.145; values_[14] = 2.131;
    values_[15] = 2.120; values_[16] = 2.110; values_[17] = 2.101; values_[18] = 2.093; values_[19] = 2.086;
    values_[20] = 2.080; values_[21] = 2.074; values_[22] = 2.069; values_[23] = 2.064; values_[24] = 2.060;
    values_[25] = 2.056; values_[26] = 2.052; values_[27] = 2.048; values_[28] = 2.045; values_[29] = 2.042;

    // Equation de droites pour approximation
    coeff_40_30_ = (2.021-2.042)/(double)(40-30);   off_40_30 = 2.042 - (30. * coeff_40_30_);
    coeff_80_40_ = (2.000-2.021)/(double)(80-40);   off_80_40 = 2.021 - (40. * coeff_80_40_);
    coeff_120_80_ = (1.980-2.00)/(double)(120-80);  off_120_80 = 2.00 - (80. * coeff_120_80_);

    infty_ = 1.960;
}

Student::~Student(){
    /* -------------------------------------------------------------------- */
    /* destructor  Libere la memoire de la "table de Student"               */
    /*                                                                      */
    /* En entree: void                                                      */
    /*                                                                      */
    /* En sortie: void                                                      */
    /* -------------------------------------------------------------------- */
    if(values_) {
        delete [] values_;
    }
}

double Student::getQuantile(int p_degre_liberte) {
    /* -------------------------------------------------------------------- */
    /* getQuantile  Permet de recuperer le quantile pour n experiences      */
    /*                                                                      */
    /* En entree: p_degre_liberte : un entier                               */
    /*                                                                      */
    /* En sortie: double                                                    */
    /* -------------------------------------------------------------------- */
    double quantile = 0.;

    if(p_degre_liberte > 0) {
        if(p_degre_liberte < 31) {
            quantile = values_[p_degre_liberte - 1];
        } else if (p_degre_liberte < 41) {
            quantile = p_degre_liberte * coeff_40_30_ + off_40_30;
        } else if (p_degre_liberte < 81) {
            quantile = p_degre_liberte * coeff_80_40_ + off_80_40;
        } else if (p_degre_liberte <= 120) {
            quantile = p_degre_liberte * coeff_120_80_ + off_80_40;
        } else {
            quantile = infty_;
        }
    }
    return quantile;
}

