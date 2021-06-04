/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <math.h>
#include "assert.h"
#include "taxes.h"

double calculerTaxeBateau(const Bateau* bateau) {
	assert(bateau);
	double taxe;
	switch (bateau->typeBateau) {
		case VOILIER:
			taxe = TAXE_BASE_VOILIER;
			taxe += bateau->specBateaux.voilier.surfaceVoile < TAXE_VOILIER_SEUIL ?
					  TAXE_VOILIER_BAS : TAXE_VOILIER_HAUT;
			break;
		case BATEAU_MOTEUR:
			taxe = TAXE_BASE_MOTEUR;
			switch (bateau->specBateaux.bateauMoteur.typeBateauMoteur) {
				case PECHE:
					taxe += bateau->specBateaux.bateauMoteur.specBateauMoteur
								  .bateauPeche.capaciteMaxPeche < TAXE_PECHE_SEUIL ?
							  TAXE_PECHE_BAS : TAXE_PECHE_HAUT;
					break;
				case PLAISANCE:
					taxe += bateau->specBateaux.bateauMoteur.puissanceMoteur <
							  TAXE_PLAISANCE_SEUIL ? TAXE_PLAISANCE_BAS :
							  TAXE_PLAISANCE_MULTIPLICATEUR_HAUT *
							  bateau->specBateaux.bateauMoteur.specBateauMoteur
								  .bateauPlaisance.longueur;
					break;
			}
			break;
	}
	return taxe;
}

double calculerSomme(const double* liste, size_t taille) {
	double somme = 0;
	for (size_t i = 0; i < taille; ++i) {
		somme += liste[i];
	}
	return somme;
}

double calculerMoyenne(const double* liste, size_t taille) {
	return calculerSomme(liste, taille) / (double) taille;
}

int cmpfunc(const void* a, const void* b) {
	if (*(double*) a > *(double*) b)
		return 1;
	else if (*(double*) a < *(double*) b)
		return -1;
	else
		return 0;
}

double calculerMediane(const double* liste, size_t taille) {
	if (!taille) {
		return 0;
	} else if (taille == 1) {
		return liste[0];
	}

	qsort((void*) liste, taille, sizeof(double), cmpfunc);
	return taille % 2 ?
			 liste[taille / 2] :
			 (liste[taille / 2 - 1] + liste[taille / 2 + 1]) / 2.0;
}

double calculerEcartType(const double* liste, size_t taille) {
	double ecartType = 0;
	double somme = calculerSomme(liste, taille);
	double moyenne = somme / (double) taille;
	for (size_t i = 0; i < taille; ++i) {
		ecartType += pow(liste[i] - moyenne, 2);
	}
	return sqrt(ecartType / (double) taille);
}

//void calculerTaxesPort(const Port port, size_t taille) {
//	size_t nbVoiliers = 0;
//	double* taxesVoiliers = (double*) calloc(taille, sizeof(double));
//	size_t nbPeches = 0;
//	double* taxesPeches = (double*) calloc(taille, sizeof(double));
//	size_t nbPlaisances = 0;
//	double* taxesPlaisances = (double*) calloc(taille, sizeof(double));
//
//	for (size_t i = 0; i < taille; ++i) {
//		switch (port[i].typeBateau) {
//			case VOILIER:
//				taxesVoiliers[nbVoiliers++] = calculerTaxeBateau(&port[i]);
//				break;
//			case BATEAU_MOTEUR:
//				switch (port[i].specBateaux.bateauMoteur.typeBateauMoteur) {
//					case PECHE:
//						taxesPeches[nbPeches++] = calculerTaxeBateau(&port[i]);
//						break;
//					case PLAISANCE:
//						taxesPlaisances[nbPlaisances++] = calculerTaxeBateau(&port[i]);
//						break;
//				}
//				break;
//		}
//	}
//
//	taxesVoiliers = realloc(taxesVoiliers, nbVoiliers * sizeof(double));
//	taxesPeches = realloc(taxesPeches, nbPeches * sizeof(double));
//	taxesPlaisances = realloc(taxesPlaisances, nbPlaisances * sizeof(double));
//
////	afficherTaxesParType(taxesVoiliers, nbVoiliers, "Voiliers");
////	afficherTaxesParType(taxesPeches, nbPeches, "Bateaux de peche");
////	afficherTaxesParType(taxesPlaisances, nbPlaisances, "Bateaux de plaisance");
//
////	free(taxesVoiliers);
////	free(taxesPeches);
////	free(taxesPlaisances);
//
////	for (size_t i = 0; i < nbVoiliers; ++i) {
////		printf("%g ", taxesVoiliers[i]);
////	}
////	printf("\n");
//}
//
//TaxeBateau** calculerTaxesPort_old(const Port port, size_t taille) {
//	TaxeBateau** taxes = (TaxeBateau**) calloc(taille, sizeof(TaxeBateau*));
//	if (taxes) {
//		for (size_t i = 0; i < taille; ++i) {
//			taxes[i] = (TaxeBateau*) malloc(sizeof(TaxeBateau));
//			if (taxes[i]) {
//				taxes[i]->bateau = &port[i];
//				taxes[i]->taxe = calculerTaxeBateau(&port[i]);
//			}
//		}
//	}
//	return taxes;
//}
