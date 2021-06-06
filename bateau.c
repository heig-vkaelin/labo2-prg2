/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Implémentation des Bateaux, celle-ci consiste principalement à
                  mettre à disposition plusieurs fonctions permettant de faciliter
                  la création des différents types de Bateaux.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include "bateau.h"

const char* const TYPE_BATEAU[] = {"Voilier", "Bateau a moteur"};
const char* const TYPE_BATEAU_MOTEUR[] = {
	"Bateau de peche", "Bateau de plaisance"
};

Bateau voilier(Nom nom, SurfaceVoile surfaceVoile) {
	assert(nom != NULL);
	return (Bateau) {nom, VOILIER, {{surfaceVoile}}};
}

Bateau bateauPeche(Nom nom, PuissanceMoteur puissanceMoteur,
						 CapaciteMaxPeche capaciteMaxPeche) {
	assert(nom != NULL);
	return (Bateau) {
		nom,
		BATEAU_MOTEUR,
		{.bateauMoteur={
			PECHE,
			{{capaciteMaxPeche}},
			puissanceMoteur
		}}
	};
}

Bateau bateauPlaisance(Nom nom, PuissanceMoteur puissanceMoteur,
							  Nom nomProprietaire, Longueur longueur) {
	assert(nom != NULL && nomProprietaire != NULL);
	return (Bateau) {
		nom,
		BATEAU_MOTEUR,
		{.bateauMoteur={
			PLAISANCE,
			{.bateauPlaisance={nomProprietaire, longueur}},
			puissanceMoteur
		}}
	};
}
