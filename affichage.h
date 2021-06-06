/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin
 Date creation  : 30.05.2021

 Description    : Module permettant d'afficher les diverses caractéristiques des
                  Bateaux ainsi que des statistiques par type de Bateau.

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
#define MSG_ECART_TYPE "Ecart type"

#define METRIQUE_TAXE "Euros"
#define METRIQUE_SURFACE "[m2]"
#define METRIQUE_PUISSANCE "[CV]"
#define METRIQUE_CAPACITE "[t]"
#define METRIQUE_LONGUEUR "[m]"

/**
 * Affiche les caractéristiques d'un Bateau dans la console
 * @param bateau
 */
void afficherBateau(const Bateau* bateau);

/**
 * Affiche les caractéristiques de tous les Bateaux du port dans la console
 * @param port : tableau de Bateaux
 * @param taille : nombre de bateaux dans le port
 */
void afficherPort(const Port port, size_t taille);

/**
 * Affiche de multiples statistiques sur le type de Bateaux voulu
 * @param port : tableau de Bateaux
 * @param taille : nombre de Bateaux dans le port
 * @param type : type du Bateau
 * @param typeMoteur : sous catégorie du Bateau si celui-ci est un Bateau à moteur
 */
void afficherStatsParType(const Port port, size_t taille,
								  bool (* condition)(const Bateau*));

#endif // PRG2_LABO2_AFFICHAGE_H
