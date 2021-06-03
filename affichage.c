/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "affichage.h"

void afficherBateau(const Bateau* bateau) {
	if (!bateau) { return; }

	printf(FORMAT_MSG "%s\n", MSG_NOM, bateau->nom);
	printf(FORMAT_MSG "%g %s\n", MSG_TAXE, bateau->taxe, METRIQUE_TAXE);

	switch (bateau->typeBateau) {
		case VOILIER:
			printf(FORMAT_MSG "%s\n", MSG_TYPE, TYPE_BATEAU[VOILIER]);
			printf(FORMAT_MSG"%d %s\n",
					 MSG_SURFACE,
					 bateau->specBateaux.voilier.surfaceVoile,
					 METRIQUE_SURFACE);
			break;
		case BATEAU_MOTEUR:
			printf(FORMAT_MSG"%s %s\n",
					 MSG_TYPE,
					 TYPE_BATEAU[BATEAU_MOTEUR],
					 TYPE_BATEAU_MOTEUR[bateau->specBateaux
						 .bateauMoteur.typeBateauMoteur]);
			printf(FORMAT_MSG"%d %s\n",
					 MSG_PUISSANCE,
					 bateau->specBateaux.bateauMoteur.puissanceMoteur,
					 METRIQUE_PUISSANCE);
			switch (bateau->specBateaux.bateauMoteur.typeBateauMoteur) {
				case PECHE:
					printf(FORMAT_MSG"%d %s\n",
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
					printf(FORMAT_MSG"%d %s\n",
							 MSG_LONGUEUR,
							 bateau->specBateaux.bateauMoteur.specBateauMoteur
								 .bateauPlaisance.longueur,
							 METRIQUE_LONGUEUR);
					break;
			}
			break;
	}
}

void afficherPort(const Port port, size_t taille) {
	if (port) {
		for (size_t i = 0; i < taille; ++i) {
			afficherBateau(&port[i]);
			printf("\n");
		}
	}
}
