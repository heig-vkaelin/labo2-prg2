/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : Programme principal ...

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

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

//typedef double Taxe;

//typedef struct {
//	const Bateau* bateau;
//	double taxe;
//} TaxeBateau;
//
typedef enum {
	SOMME, MOYENNE, MEDIANNE, ECART_TYPE
} Statistiques;

//typedef TaxeBateau* TaxesPort;

double calculerTaxeBateau(const Bateau* bateau);

//void calculerTaxesPort(const Port port, size_t taille);

double calculerSomme(const double* liste, size_t taille);

double calculerMoyenne(const double* liste, size_t taille);

double calculerMediane(const double* liste, size_t taille);

double calculerEcartType(const double* liste, size_t taille);

//TaxeBateau** calculerTaxesPort_old(const Port port, size_t taille);

#endif // PRG2_LABO2_TAXES_H
