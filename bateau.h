/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO2_BATEAU_H
#define PRG2_LABO2_BATEAU_H

#include <stdint.h>

typedef const char* Nom;
typedef enum {
	VOILIER, BATEAU_MOTEUR
} TypeBateau;
typedef enum {
	PECHE, PLAISANCE
} TypeBateauMoteur;
typedef uint16_t SurfaceVoile;
typedef uint16_t PuissanceMoteur;
typedef uint8_t CapaciteMaxPeche;
typedef uint8_t Longueur;

extern const char* const TYPE_BATEAU[];
extern const char* const TYPE_BATEAU_MOTEUR[];

typedef struct {
	SurfaceVoile surfaceVoile; // en mètres-carrés [m²]
} Voilier;

typedef struct {
	CapaciteMaxPeche capaciteMaxPeche; // en tonnes [t]
} BateauPeche;

typedef struct {
	Nom nomProprietaire;
	Longueur longueur; // en mètres [m]
} BateauPlaisance;

typedef union {
	BateauPeche bateauPeche;
	BateauPlaisance bateauPlaisance;
} SpecBateauMoteur;

typedef struct {
	TypeBateauMoteur typeBateauMoteur;
	SpecBateauMoteur specBateauMoteur;
	PuissanceMoteur puissanceMoteur; // en nombre de chevaux [CV]
} BateauMoteur;

typedef union {
	Voilier voilier;
	BateauMoteur bateauMoteur;
} SpecBateaux;

typedef struct {
	Nom nom;
	TypeBateau typeBateau;
	SpecBateaux specBateaux;
	double taxe;
} Bateau;

typedef Bateau Port[];

Bateau voilier(Nom nom, SurfaceVoile surfaceVoile);

Bateau bateauPeche(Nom nom, PuissanceMoteur puissanceMoteur,
						 CapaciteMaxPeche capaciteMaxPeche);

Bateau bateauPlaisance(Nom nom, PuissanceMoteur puissanceMoteur,
							  Nom nomProprietaire, Longueur longueur);

#endif // PRG2_LABO2_BATEAU_H
