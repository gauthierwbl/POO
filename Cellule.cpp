#include "Cellule.h"

// Constructeur de la classe Cellule
// Initialise l'état actuel avec etatInitial et l'état suivant par défaut à faux (false)
Cellule::Cellule(bool etatInitial) : etatActuel(etatInitial), etatSuivant(false), etatPrecedent(false) {}

// Accesseur pour obtenir l'état actuel de la cellule
bool Cellule::getEtatActuel() const {
    return etatActuel; // Retourne l'état actuel
}

// Mutateur pour définir l'état actuel de la cellule
void Cellule::setEtatActuel(bool etat) {
    etatActuel = etat; // Met à jour l'état actuel
}

// Accesseur pour obtenir l'état suivant de la cellule
bool Cellule::getEtatSuivant() const {
    return etatSuivant; // Retourne l'état suivant
}

// Mutateur pour définir l'état suivant de la cellule
void Cellule::setEtatSuivant(bool etat) {
    etatSuivant = etat; // Met à jour l'état suivant
}

// Accesseur pour obtenir l'état précédent de la cellule
bool Cellule::getEtatPrecedent() const {
    return etatPrecedent; // Retourne l'état précédent
}

// Mutateur pour définir l'état précédent de la cellule
void Cellule::setEtatPrecedent(bool etat) {
    etatPrecedent = etat; // Met à jour l'état précédent
}

// Destructeur virtuel
Cellule::~Cellule() {
    // Peut contenir des opérations de nettoyage si nécessaire
}
