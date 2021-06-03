/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : Programme principal ...

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bateau.h"
#include "affichage.h"
#include "taxes.h"

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

void afficherTaxesParType(const double* liste, size_t taille, Nom nom) {
	printf("Statistiques - %s\n", nom);
	printf("Somme: %g Euros\n", calculerSomme(liste, taille));
	printf("Moyenne: %g Euros\n", calculerMoyenne(liste, taille));
	printf("Mediane: %g Euros\n", calculerMediane(liste, taille));
	printf("Ecart type: %g Euros\n\n", calculerEcartType(liste, taille));
}

void afficherTaxes(const Port port, size_t taille) {
	size_t nbVoiliers = 0;
	double* taxesVoiliers = (double*) calloc(taille, sizeof(double));
	size_t nbPeches = 0;
	double* taxesPeches = (double*) calloc(taille, sizeof(double));
	size_t nbPlaisances = 0;
	double* taxesPlaisances = (double*) calloc(taille, sizeof(double));

	for (size_t i = 0; i < taille; ++i) {
		switch (port[i].typeBateau) {
			case VOILIER:
				taxesVoiliers[nbVoiliers++] = port[i].taxe;
				break;
			case BATEAU_MOTEUR:
				switch (port[i].specBateaux.bateauMoteur.typeBateauMoteur) {
					case PECHE:
						taxesPeches[nbPeches++] = port[i].taxe;
						break;
					case PLAISANCE:
						taxesPlaisances[nbPlaisances++] = port[i].taxe;
						break;
				}
				break;
		}
	}

	afficherTaxesParType(taxesVoiliers, nbVoiliers, "Voiliers");
	afficherTaxesParType(taxesPeches, nbPeches, "Bateaux de peche");
	afficherTaxesParType(taxesPlaisances, nbPlaisances, "Bateaux de plaisance");

	free(taxesVoiliers);
	free(taxesPeches);
	free(taxesPlaisances);

//	for (size_t i = 0; i < nbVoiliers; ++i) {
//		printf("%g ", taxesVoiliers[i]);
//	}
//	printf("\n");
}

int main() {
	Port port = {
		voilier("voilier1", 120),
		voilier("voilier2", 250),
		voilier("voilier3", 12),
		voilier("voilier4", 3500),
//		voilier("voilier5", 111),
		bateauPlaisance("Titanic", 51000, "John Pierpont Morgan", (Longueur) 269),
		bateauPeche("VLADIVOSTOK 2000", 4000, (CapaciteMaxPeche) 14000),
		bateauPeche("GOLDEN ALASKA", 400, (CapaciteMaxPeche) 250),
	};

	const size_t NB_BATEAUX = sizeof(port) / sizeof(Bateau);

	afficherPort(port, NB_BATEAUX);
	afficherTaxes(port, NB_BATEAUX);

//	typedef enum {
//		T_VOILIER, T_PECHE, T_PLAISANCE
//	} OrdreType;

	return EXIT_SUCCESS;
}
