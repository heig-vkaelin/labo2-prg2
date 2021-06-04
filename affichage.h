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

#define FORMAT_MSG "%-21s : "
#define SEPARATEUR "-----------------------------------------------------"
#define MSG_NOM "Nom"
#define MSG_TAXE "Taxe"
#define MSG_TYPE "Categorie"
#define MSG_SURFACE "Surface de la voile"
#define MSG_PUISSANCE "Puissance du moteur"
#define MSG_CAPACITE "Capacite max de peche"
#define MSG_PROPRIETAIRE "Nom du proprietaire"
#define MSG_LONGUEUR "Longueur"

#define FORMAT_MSG_STATS "%-14s : "
#define SEPARATEUR_STATS "-----------------------------"
#define MSG_SOMME "Somme"
#define MSG_MOYENNE "Moyenne"
#define MSG_MEDIANE "Mediane"
#define MSG_ECART "Ecart type"

#define METRIQUE_TAXE "Euros"
#define METRIQUE_SURFACE "[m2]"
#define METRIQUE_PUISSANCE "[CV]"
#define METRIQUE_CAPACITE "[t]"
#define METRIQUE_LONGUEUR "[m]"

void afficherBateau(const Bateau* bateau);

void afficherPort(const Port port, size_t taille);

void afficherTaxesParType(const Port port, size_t taille, TypeBateau type,
								  TypeBateauMoteur typeMoteur);

#endif // PRG2_LABO2_AFFICHAGE_H
