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

double* separerTaxesParType(const Port port, size_t* taille,
									 TypeBateau type, TypeBateauMoteur typeMoteur) {
	size_t nbBateaux = 0;
	double* taxes = (double*) calloc(*taille, sizeof(double));

	if (!taxes) {
		return NULL;
	}

	for (size_t i = 0; i < *taille; ++i) {
		if (port[i].typeBateau == type) {
			if (type == VOILIER ||
				 port[i].specBateaux.bateauMoteur.typeBateauMoteur == typeMoteur) {
				taxes[nbBateaux++] = calculerTaxeBateau(&port[i]);
			}
		}
	}

	taxes = (double*) realloc(taxes, nbBateaux * sizeof(double));
	*taille = taxes ? nbBateaux : 0;

	return taxes;
}
