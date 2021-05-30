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

int main() {
	Port port = {
		voilier("Going Merry", 120),
		voilier("Thousand Sunny", 250),
		bateauPlaisance("Titanic", 51000, "John Pierpont Morgan", (Longueur) 269),
	};
	afficherPort(port, sizeof(port) / sizeof(Bateau));

	return EXIT_SUCCESS;
}
