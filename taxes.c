//
// Created by Valentin on 03.06.2021.
//

#include <stdlib.h>
#include "assert.h"
#include "taxes.h"

double calculerTaxeBateau(const Bateau* bateau) {
	assert(bateau);
	double taxe;
	switch (bateau->typeBateau) {
		case VOILIER:
			taxe = TAXE_BASE_VOILIER;
			taxe += bateau->specBateaux.voilier.surfaceVoile < TAXE_VOILIER_SEUIL ?
					  TAXE_VOILIER_BAS : TAXE_VOILIER_HAUT;
			break;
		case BATEAU_MOTEUR:
			taxe = TAXE_BASE_MOTEUR;
			switch (bateau->specBateaux.bateauMoteur.typeBateauMoteur) {
				case PECHE:
					taxe += bateau->specBateaux.bateauMoteur.specBateauMoteur
								  .bateauPeche.capaciteMaxPeche < TAXE_PECHE_SEUIL ?
							  TAXE_PECHE_BAS : TAXE_PECHE_HAUT;
					break;
				case PLAISANCE:
					taxe += bateau->specBateaux.bateauMoteur.puissanceMoteur <
							  TAXE_PLAISANCE_SEUIL ? TAXE_PLAISANCE_BAS :
							  TAXE_PLAISANCE_MULTIPLICATEUR_HAUT *
							  bateau->specBateaux.bateauMoteur.specBateauMoteur
								  .bateauPlaisance.longueur;
					break;
			}
			break;
	}
	return taxe;
}

TaxeBateau** calculerTaxesPort(const Port port, size_t taille) {
	TaxeBateau** taxes = (TaxeBateau**) calloc(taille, sizeof(TaxeBateau*));
	if (taxes) {
		for (size_t i = 0; i < taille; ++i) {
			taxes[i] = (TaxeBateau*) malloc(sizeof(TaxeBateau));
			if (taxes[i]) {
				taxes[i]->bateau = &port[i];
				taxes[i]->taxe = calculerTaxeBateau(&port[i]);
			}
		}
	}
	return taxes;
}

double statistiquesParType(const double* taxes, Statistiques stats) {


	return 0;
}
