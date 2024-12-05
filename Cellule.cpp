#include "Cellule.h"
#include <iostream>

// Constructeur de la classe Cellule
// Initialise l'état actuel avec etatInitial et l'état suivant par défaut à faux (false)
Cellule::Cellule(bool etatInitial) : etatActuel(etatInitial), etatSuivant(false) {}

// Accesseur pour obtenir l'état actuel de la cellule
bool Cellule::getEtatActuel() const {
    return etatActuel; // Retourne l'état actuel
}

// Mutateur pour définir l'état actuel de la cellule
void Cellule::setEtatActuel(bool etat) {
    etatActuel = etat; // Met à jour l'état actuel
}

// Méthode pour mettre à jour l'état de la cellule
void Cellule::mettreAJour() {
    etatActuel = etatSuivant; // Met l'état actuel à l'état suivant
}

// Destructeur virtuel
Cellule::~Cellule() {
    // Peut contenir des opérations de nettoyage si nécessaire
}
