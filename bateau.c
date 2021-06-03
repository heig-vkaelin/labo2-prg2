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
#include "taxes.h"

const char* const TYPE_BATEAU[] = {"Voilier", "Bateau a moteur"};
const char* const TYPE_BATEAU_MOTEUR[] = {"de peche", "de plaisance"};

Bateau voilier(Nom nom, SurfaceVoile surfaceVoile) {
	Bateau b = {nom, VOILIER, {{surfaceVoile}}, 0.0};
	b.taxe = calculerTaxeBateau(&b);
	return b;
}

Bateau bateauPeche(Nom nom, PuissanceMoteur puissanceMoteur,
						 CapaciteMaxPeche capaciteMaxPeche) {
	Bateau b = {
		nom,
		BATEAU_MOTEUR,
		{.bateauMoteur={
			PECHE,
			{{capaciteMaxPeche}},
			puissanceMoteur
		}},
		0.0
	};
	b.taxe = calculerTaxeBateau(&b);
	return b;
}

Bateau bateauPlaisance(Nom nom, PuissanceMoteur puissanceMoteur,
							  Nom nomProprietaire, Longueur longueur) {
	Bateau b = {
		nom,
		BATEAU_MOTEUR,
		{.bateauMoteur={
			PLAISANCE,
			{.bateauPlaisance={nomProprietaire, longueur}},
			puissanceMoteur
		}},
		0.0
	};
	b.taxe = calculerTaxeBateau(&b);
	return b;
}
