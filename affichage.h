/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_LABO2_AFFICHAGE_H
#define PRG2_LABO2_AFFICHAGE_H

#include <stdlib.h>
#include "bateau.h"

#define FORMAT_MSG "%-20s : "
#define MSG_NOM "Nom du bateau"
#define MSG_TYPE "Type du bateau"
#define MSG_SURFACE "Surface voile"
#define MSG_PUISSANCE "Puissance moteur"
#define MSG_CAPACITE "Capacite max de peche"
#define MSG_PROPRIETAIRE "Nom du proprietaire"
#define MSG_LONGUEUR "Longueur"

#define METRIQUE_SURFACE "[m2]"
#define METRIQUE_PUISSANCE "[CV]"
#define METRIQUE_LONGUEUR "[m]"
#define METRIQUE_CAPACITE "[t]"

void afficherBateau(const Bateau* bateau);

void afficherPort(const Port port, size_t taille);

#endif // PRG2_LABO2_AFFICHAGE_H
