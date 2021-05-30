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

#define METRIQUE_SURFACE "m2"
#define METRIQUE_PUISSANCE "CV"
#define METRIQUE_LONGUEUR "m"
#define TAXE_VOILIER 50
#define TAXE_BATEAU_MOTEUR 100

typedef const char* Nom;
typedef enum {
	VOILIER, BATEAU_MOTEUR
} TypeBateau;
typedef enum {
	PECHE, PLAISANCE
} TypeBateauMoteur;
typedef uint16_t Surface;
typedef uint16_t PuissanceMoteur;
typedef uint8_t CapaciteMaxPeche;
typedef uint8_t Longueur;

const char* const TYPE_BATEAU[] = {"Voilier", "Bateau a moteur"};
const char* const TYPE_BATEAU_MOTEUR[] = {"Bateau de peche", "Bateau de plaisance"};

typedef struct {
	CapaciteMaxPeche capaciteMaxPeche;
} BateauPeche;

typedef struct {
	Nom nomProprio;
	Longueur longueur;
} BateauPlaisance;

typedef union {
	BateauPeche bateauPeche;
	BateauPlaisance bateauPlaisance;
} SpecBateauMoteur;

typedef struct {
	TypeBateauMoteur typeBateauMoteur;
	SpecBateauMoteur specBateauMoteur;
	PuissanceMoteur puissanceMoteur;
} BateauMoteur;

typedef struct {
	Surface surface;
} Voilier;

typedef union {
	Voilier voilier;
	BateauMoteur bateauMoteur;
} SpecBateaux;

typedef struct {
	Nom nomBateau;
	TypeBateau typeBateau;
	SpecBateaux specBateaux;
} Personne;

#endif //PRG2_LABO2_BATEAU_H
