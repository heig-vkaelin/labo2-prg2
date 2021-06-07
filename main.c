/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Programme principal montrant l'implémentation du logiciel de
                  gestion de port. Il est possible de créer des Bateaux de
                  différents types, d'afficher leurs caractéristiques ainsi que leur
                  taxe dans la console et finalement d'afficher quelques
                  statistiques par type de Bateau.

 Remarque(s)    : Il ne s'agit pas d'un programme de test complet du logiciel, mais
                  uniquement d'un exemple de son utilisation.

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"
#include "affichage.h"

int main() {
	Port port = {
		voilier("Black Pearl", 120),
		voilier("Queen Anne Revenge", 250),
		voilier("La Neptune", 12),
		voilier("Hollandais volant", 3500),
		voilier("Thousand Sunny", 111),
		bateauPlaisance("Titanic", 51000, "John Pierpont Morgan", 255),
		bateauPlaisance("La Suisse", 420, "M. Smith", 58),
		bateauPlaisance("MSC Fantasia", 1230, "John Doe", 127),
		bateauPlaisance("Vevey", 150, "Vessel company", 18),
		bateauPeche("Koulapik", 4000, 250),
		bateauPeche("Vladivostok 2000", 220, 12),
		bateauPeche("Golden Alaska", 250, 40),
	};

	const size_t NB_BATEAUX = sizeof(port) / sizeof(Bateau);

	printf("================\n");
	printf("Bateaux du port:\n");
	printf("================\n\n");
	afficherPort(port, NB_BATEAUX);

	printf("================================\n");
	printf("Statistiques par type de bateau:\n");
	printf("================================\n\n");
	afficherStatsParType(port, NB_BATEAUX, TYPE_BATEAU[VOILIER], estVoilier);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, TYPE_BATEAU_MOTEUR[PECHE], estBateauPeche);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, TYPE_BATEAU_MOTEUR[PLAISANCE],
								estBateauPlaisance);

	return EXIT_SUCCESS;
}
