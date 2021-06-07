/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Programme principal montrant l'implémentation du logiciel de
                  gestion de port. Il est possible de créer des Bateaux de
                  différents types, d'afficher leurs caractéristiques ainsi que leur
                  taxes dans la console et finalement d'afficher quelques
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
		voilier("voilier1", 120),
		voilier("voilier2", 250),
		voilier("voilier3", 12),
		voilier("voilier4", 3500),
		voilier("voilier5", 111),
		bateauPlaisance("plaisance1", 51000, "John Pierpont Morgan", 255),
		bateauPlaisance("plaisance2", 420, "M. Smith", 58),
		bateauPlaisance("plaisance3", 1230, "John Doe", 127),
		bateauPlaisance("plaisance4", 150, "Vessel company", 18),
		bateauPeche("peche1", 4000, 250),
		bateauPeche("peche2", 220, 12),
		bateauPeche("peche3", 250, 40),
	};

	const size_t NB_BATEAUX = sizeof(port) / sizeof(Bateau);

	printf("================\n");
	printf("Bateaux du port:\n");
	printf("================\n\n");
	afficherPort(port, NB_BATEAUX);

	printf("================================\n");
	printf("Statistiques par type de bateau:\n");
	printf("================================\n\n");
	// TODO: dernier param optionnel
	afficherStatsParType(port, NB_BATEAUX, VOILIER, 0);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, BATEAU_MOTEUR, PECHE);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, BATEAU_MOTEUR, PLAISANCE);

	return EXIT_SUCCESS;
}
