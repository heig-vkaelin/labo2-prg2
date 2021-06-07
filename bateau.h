/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Mets à disposition les bases nécessaires à la gestion du port.
                  Structure les différents types de Bateaux du Port.                  

 Remarque(s)    : Les taxes, étant des champs calculés, ne sont pas stockées
                  directement dans la structure du Bateau. Il faut les calculer en
                  utilisant les fonctions mises à disposition dans le module taxes.

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
} Bateau;

typedef Bateau Port[];

/**
 * Permet de construire un bateau de type voilier
 * @param nom : nom du bateau
 * @param surfaceVoile : surface de la voile en mètres-carrés
 * @return la structure du bateau
 */
Bateau voilier(Nom nom, SurfaceVoile surfaceVoile);

/**
 * Permet de construire un bateau à moteur de pêche
 * @param nom : nom du bateau
 * @param puissanceMoteur : en nombre de chevaux
 * @param capaciteMaxPeche : en tonnes
 * @return la structure du bateau
 */
Bateau bateauPeche(Nom nom, PuissanceMoteur puissanceMoteur,
						 CapaciteMaxPeche capaciteMaxPeche);

/**
 * Permet de construire un bateau à moteur de plaisance
 * @param nom : nom du bateau
 * @param puissanceMoteur  : en nombre de chevaux
 * @param nomProprietaire : nom du propriétaire
 * @param longueur : en mètres
 * @return la structure du bateau
 */
Bateau bateauPlaisance(Nom nom, PuissanceMoteur puissanceMoteur,
							  Nom nomProprietaire, Longueur longueur);

#endif // PRG2_LABO2_BATEAU_H
