/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Implémentation de toutes les fonctions d'affichage de l'outil de
                  gestion de port.

 Remarque(s)    : Les différents messages affichés dans la console sont tous
                  modifiables via le fichier header.

                  Des cas "default" ont été ajoutés dans les conditions du switch
                  case sur les types de Bateaux pour deux raisons principales:
                  - Si l'utilisateur cast une valeur incorrecte en type de bateau,
                    le programme affichera une erreur.
                  - Si dans le futur un nouveau type de Bateau est ajouté, une
                    erreur surviendra si les switch case n'ont pas été adaptés pour
                    prendre en compte ce nouveau type.

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include "affichage.h"
#include "taxes.h"

void afficherBateau(const Bateau* bateau) {
	assert(bateau != NULL);
	puts(SEPARATEUR);
	printf(FORMAT_MSG "%s\n", MSG_NOM, bateau->nom);
	printf(FORMAT_MSG "%s\n", MSG_TYPE, TYPE_BATEAU[bateau->typeBateau]);

	switch (bateau->typeBateau) {
		case VOILIER:
			printf(FORMAT_MSG"%"PRIu16" %s\n",
					 MSG_SURFACE,
					 bateau->specBateaux.voilier.surfaceVoile,
					 METRIQUE_SURFACE);
			break;
		case BATEAU_MOTEUR:
			printf(FORMAT_MSG"%s\n",
					 MSG_TYPE_MOTEUR,
					 TYPE_BATEAU_MOTEUR[
						 bateau->specBateaux.bateauMoteur.typeBateauMoteur
					 ]);
			printf(FORMAT_MSG"%"PRIu16" %s\n",
					 MSG_PUISSANCE,
					 bateau->specBateaux.bateauMoteur.puissanceMoteur,
					 METRIQUE_PUISSANCE);
			switch (bateau->specBateaux.bateauMoteur.typeBateauMoteur) {
				case PECHE:
					printf(FORMAT_MSG"%"PRIu8" %s\n",
							 MSG_CAPACITE,
							 bateau->specBateaux.bateauMoteur.specBateauMoteur
								 .bateauPeche.capaciteMaxPeche,
							 METRIQUE_CAPACITE);
					break;
				case PLAISANCE:
					printf(FORMAT_MSG"%s\n",
							 MSG_PROPRIETAIRE,
							 bateau->specBateaux.bateauMoteur.specBateauMoteur
								 .bateauPlaisance.nomProprietaire);
					printf(FORMAT_MSG"%"PRIu8" %s\n",
							 MSG_LONGUEUR,
							 bateau->specBateaux.bateauMoteur.specBateauMoteur
								 .bateauPlaisance.longueur,
							 METRIQUE_LONGUEUR);
					break;
				default:
					assert(!(bool) "Le type de Bateau à moteur n'existe pas.");
			}
			break;
		default:
			assert(!(bool) "Le type de Bateau n'existe pas.");
	}
	printf(FORMAT_MSG "%g %s\n", MSG_TAXE, calculerTaxeBateau(bateau), METRIQUE_TAXE);
	puts(SEPARATEUR);
}

void afficherPort(const Port port, size_t taille) {
	assert(port != NULL);
	for (size_t i = 0; i < taille; ++i) {
		afficherBateau(&port[i]);
		printf("\n");
	}
}

void afficherStatsParType(const Port port, size_t taille,
								  bool (* condition)(const Bateau*)) {
	assert(port != NULL);
	size_t nbBateaux = taille;
	double* taxes = separerTaxesParType(port, &nbBateaux, condition);

	if (!taxes) {
		return;
	}

	const char* strType = "Todo";
//	if (type == VOILIER) {
//		strType = TYPE_BATEAU[VOILIER];
//	} else {
//		strType = TYPE_BATEAU_MOTEUR[typeMoteur];
//	}

	// TODO: remove DEBUG
	printf("%s\n", strType);
	for (size_t i = 0; i < nbBateaux; ++i) {
		printf("%g ", taxes[i]);
	}
	printf("\n");

	puts(SEPARATEUR_STATS);
	printf("%s\n", strType);
	printf(FORMAT_MSG_STATS"%.2f %s\n",
			 MSG_SOMME,
			 calculerSomme(taxes, nbBateaux),
			 METRIQUE_TAXE);
	printf(FORMAT_MSG_STATS"%.2f %s\n",
			 MSG_MOYENNE,
			 calculerMoyenne(taxes, nbBateaux),
			 METRIQUE_TAXE);
	printf(FORMAT_MSG_STATS"%.2f %s\n",
			 MSG_MEDIANE,
			 calculerMediane(taxes, nbBateaux),
			 METRIQUE_TAXE);
	printf(FORMAT_MSG_STATS"%.2f %s\n",
			 MSG_ECART_TYPE,
			 calculerEcartType(taxes, nbBateaux),
			 METRIQUE_TAXE);
	puts(SEPARATEUR_STATS);

	free(taxes);
	taxes = NULL;
}
