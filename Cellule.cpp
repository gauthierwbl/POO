#include "Cellule.h"
#include <iostream>

Cellule::Cellule() : etatActuel(false), etatSuivant(false) {}

bool Cellule::getEtatActuel() const {
    return etatActuel;
}

void Cellule::setEtatActuel(bool etat) {
    etatActuel = etat;
}

void Cellule::mettreAJour() {
    etatActuel = etatSuivant;
}
