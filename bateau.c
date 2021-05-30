/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.c
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <string.h>
#include "bateau.h"

const char* const TYPE_BATEAU[] = {"Voilier", "Bateau a moteur"};
const char* const TYPE_BATEAU_MOTEUR[] = {"Bateau de peche", "Bateau de plaisance"};

Bateau voilier(Nom nom, SurfaceVoile surfaceVoile) {
	return (Bateau) {nom, VOILIER, {{surfaceVoile}}};
}

Bateau bateauPeche(Nom nom, PuissanceMoteur puissanceMoteur,
						 CapaciteMaxPeche capaciteMaxPeche) {
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
