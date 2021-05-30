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
#include "bateau.h"

int main() {
	Bateau luffy = voilier("Thousand Sunny", 250);
	printf("Type du bateau: %s\n", TYPE_BATEAU[luffy.typeBateau]);
	printf("Nom du bateau: %s\n", luffy.nom);
	printf("Surface voile: %d\n\n", luffy.specBateaux.voilier.surfaceVoile);

	Bateau titanic = bateauPlaisance("Titanic", 51000, "John Pierpont Morgan",
												(Longueur) 269);
	printf("Type du bateau: %s\n", TYPE_BATEAU[titanic.typeBateau]);
	printf("Type de bateau moteur: %s\n",
			 TYPE_BATEAU_MOTEUR[titanic.specBateaux.bateauMoteur.typeBateauMoteur]);
	printf("Nom du bateau: %s\n", titanic.nom);
	printf("Nom du proprietaire: %s\n",
			 titanic.specBateaux.bateauMoteur.specBateauMoteur.bateauPlaisance.nomProprietaire);
	printf("Longueur: %d\n",
			 titanic.specBateaux.bateauMoteur.specBateauMoteur.bateauPlaisance.longueur);
	printf("Puissance moteur: %d\n",
			 titanic.specBateaux.bateauMoteur.puissanceMoteur);

	return EXIT_SUCCESS;
}
