/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Joel Dos Santos Matias, Géraud Silvestri, Valentin Kaelin,
 Date creation  : 30.05.2021

 Description    : -

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

// typedef double Taxe;

/**
 * Calcule la taxe du Bateau en fonction de ses caractéristiques
 * @param bateau
 * @return la taxe du Bateau
 */
double calculerTaxeBateau(const Bateau* bateau);

/**
 * Calcule la somme des taxes entrées en paramètre
 * @param liste : liste de taxes
 * @param taille : nombre de taxes
 * @return la somme des taxes
 */
double calculerSomme(const double* liste, size_t taille);

/**
 * Calcule la moyenne des taxes entrées en paramètre
 * @param liste : liste de taxes
 * @param taille : nombre de taxes
 * @return la moyenne des taxes
 */
double calculerMoyenne(const double* liste, size_t taille);

/**
 * Calcule la médiane des taxes entrées en paramètre
 * @param liste : liste de taxes
 * @param taille : nombre de taxes
 * @return la médiane des taxes
 */
double calculerMediane(const double* liste, size_t taille);

/**
 * Calcule l'écart-type des taxes entrées en paramètre
 * @param liste : liste de taxes
 * @param taille : nombre de taxes
 * @return l'écart-type des taxes
 */
double calculerEcartType(const double* liste, size_t taille);

/**
 * Sépare et calcule les taxes du type de Bateaux voulu
 * @param port : tableau de Bateaux
 * @param taille : nombre de Bateaux du port, est modifiée par la fonction pour
 * correspondre au nombre de Bateaux du type voulu
 * @param type : type du Bateau
 * @param typeMoteur : sous catégorie du Bateau si celui-ci est un Bateau à moteur
 * @return la liste des taxes
 */
double* separerTaxesParType(const Port port, size_t* taille,
									 TypeBateau type, TypeBateauMoteur typeMoteur);

#endif // PRG2_LABO2_TAXES_H
