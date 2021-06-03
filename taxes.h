//
// Created by Valentin on 03.06.2021.
//

#ifndef PRG2_LABO2_TAXES_H
#define PRG2_LABO2_TAXES_H

#include "bateau.h"

#define TAXE_BASE_VOILIER 50.0
#define TAXE_BASE_MOTEUR 100.0

#define TAXE_VOILIER_BAS 0.0
#define TAXE_VOILIER_HAUT 25.0
#define TAXE_VOILIER_SEUIL 200

#define TAXE_PECHE_BAS 0.0
#define TAXE_PECHE_HAUT 100.0
#define TAXE_PECHE_SEUIL 20

#define TAXE_PLAISANCE_BAS 50.0
#define TAXE_PLAISANCE_MULTIPLICATEUR_HAUT 15.0
#define TAXE_PLAISANCE_SEUIL 100

typedef struct {
	const Bateau* bateau;
	double taxe;
} TaxeBateau;

typedef enum {
	SOMME, MOYENNE, MEDIANNE, ECART_TYPE
} Statistiques;

//typedef TaxeBateau* TaxesPort;

double calculerTaxeBateau(const Bateau* bateau);

TaxeBateau** calculerTaxesPort(const Port port, size_t taille);

#endif //PRG2_LABO2_TAXES_H
