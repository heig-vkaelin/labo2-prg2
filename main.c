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

#include <stdlib.h>
#include "bateau.h"
#include "affichage.h"
#include "taxes.h"

int main() {
	Port port = {
		voilier("Going Merry", 120),
		voilier("Thousand Sunny", 250),
		bateauPlaisance("Titanic", 51000, "John Pierpont Morgan", (Longueur) 269),
		bateauPeche("VLADIVOSTOK 2000", 4000, (CapaciteMaxPeche) 14000),
		bateauPeche("GOLDEN ALASKA", 400, (CapaciteMaxPeche) 250),
	};

	const size_t NB_BATEAUX = sizeof(port) / sizeof(Bateau);

	TaxeBateau** taxes = calculerTaxesPort(port, NB_BATEAUX);

	// TODO:
	// 3) afficher, par type de bateau (voilier, bateau de pêche, bateau de plaisance),
	// la somme, la moyenne, la médiane et l'écart-type des taxes annuelles dues

	/*
	 * [
	 * 	[voilier] = [1, 2, 3, 2276],
	 * 	[peche] = [1, 2, 3, 2276],
	 * 	[plaisance] = [1, 2, 3, 2276]
	 * ]
	 */

	// TODO: comment trouver dynamiquement le nombre de types de bateaux différents
	// (3 dans notre cas)

	const size_t NB_TYPES = 3;
//	double** taxesParType = (double**) calloc(NB_TYPES, sizeof(double*));
//	for (size_t i = 0; i < NB_TYPES; ++i) {
//		taxesParType[i] = calloc(NB_BATEAUX, sizeof(double));
//		if (!taxesParType[i]) { return EXIT_FAILURE; }
//	}


		TaxesParType taxesParType = {};


	// Ajout des bateaux dans leurs catégories
//	for (size_t i = 0; i < NB_BATEAUX; ++i) {
//		switch (taxes[i]->bateau->typeBateau) {
//			case VOILIER:
//
//				break;
//			case BATEAU_MOTEUR:
//				break;
//		}
//	}

	double moyenne = statistiquesParType(taxes, MOYENNE);

	if (taxes && taxesParType) {
		afficherPort(port, NB_BATEAUX, taxes);

		return EXIT_SUCCESS;
	}


	return EXIT_FAILURE;
}
