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
#include <stdbool.h>
#include "bateau.h"
#include "affichage.h"

bool estVoilier(const Bateau* bateau) {
	return bateau != NULL && bateau->typeBateau == VOILIER;
}

bool estBateauPlaisance(const Bateau* bateau) {
	return bateau != NULL && bateau->typeBateau == BATEAU_MOTEUR
			 && bateau->specBateaux.bateauMoteur.typeBateauMoteur == PLAISANCE;
}

bool estBateauPeche(const Bateau* bateau) {
	return bateau != NULL && bateau->typeBateau == BATEAU_MOTEUR
			 && bateau->specBateaux.bateauMoteur.typeBateauMoteur == PECHE;
}

int main() {
	Port port = {
		voilier("voilier1", 120),
		voilier("voilier2", 250),
		voilier("voilier3", 12),
		voilier("voilier4", 3500),
		voilier("voilier5", 111),
//		bateauPlaisance("plaisance1", 51000, "John Pierpont Morgan", 255),
//		bateauPlaisance("plaisance2", 420, "M. Smith", 58),
//		bateauPlaisance("plaisance3", 1230, "John Doe", 127),
//		bateauPlaisance("plaisance4", 150, "Vessel company", 18),
//		bateauPeche("peche1", 4000, 250),
//		bateauPeche("peche2", 220, 12),
//		bateauPeche("peche3", 250, 40),

		bateauPlaisance("Titanic", 46000, "John Pierpont Morgan", 255),
		bateauPlaisance("Pilar", 50, "Ernest Hemingway", 38),
		bateauPlaisance("Spirit of Australia", 100, "Ken Warby", 10),
		bateauPlaisance("Queen Mary", 16000, "Jack Wrather", 255),

		bateauPeche("Angoumois", 200, 15),
		bateauPeche("Marie-Louise", 150, 10),
		bateauPeche("Sainte-Bernadette", 100, 20),
		bateauPeche("Amphitrite", 200, 25)
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
	afficherStatsParType(port, NB_BATEAUX, estVoilier);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, estBateauPeche);
	printf("\n");
	afficherStatsParType(port, NB_BATEAUX, estBateauPlaisance);

	return EXIT_SUCCESS;
}
