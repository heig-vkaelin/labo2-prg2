/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Implémentation des fonctions concernant les taxes des Bateaux du
                  port.

 Remarque(s)    : Lors de la séparation des taxes par type, la vérification de
                  que l'allocation mémoire est réussie est laissée au développeur.
                  Dans le cas où on problème aurait été rencontré, NULL serait
                  renvoyé.

                  Les taxes sont représentées comme des nombres réels malgré le
                  fait que nous utilisions uniquement des nombres entiers, par
                  mesure d'évolutivité.

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "taxes.h"

/**
 * Fonction de comparaison de double utilisée dans l'algorithme de tri quick sort
 */
int cmpfunc(const void* a, const void* b) {
	assert(a != NULL && b != NULL);
	if (*(double*) a > *(double*) b)
		return 1;
	else if (*(double*) a < *(double*) b)
		return -1;
	else
		return 0;
}

double calculerTaxeBateau(const Bateau* bateau) {
	assert(bateau != NULL);
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
	assert(liste != NULL);
	double somme = 0;
	for (size_t i = 0; i < taille; ++i) {
		somme += liste[i];
	}
	return somme;
}

double calculerMoyenne(const double* liste, size_t taille) {
	assert(liste != NULL);
	return calculerSomme(liste, taille) / (double) taille;
}

double calculerMediane(const double* liste, size_t taille) {
	assert(liste != NULL);
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
	assert(liste != NULL);
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
	assert(port != NULL && taille != NULL);
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
	// Vérification que la réallocation mémoire s'est bien déroulée
	*taille = taxes ? nbBateaux : 0;

	return taxes;
}
