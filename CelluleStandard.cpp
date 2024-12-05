#include "CelluleStandard.h"
#include <iostream>

// Constructeur de la classe CelluleStandard
// Appelle le constructeur de la classe de base Cellule avec l'état initial
CelluleStandard::CelluleStandard(bool etatInitial) : Cellule(etatInitial) {}

// Implémentation de la méthode pour calculer l'état suivant
void CelluleStandard::calculerEtatSuivant(int nbVoisinesVivantes) {
    if (etatActuel) {
        // Règle : Une cellule vivante reste vivante avec 2 ou 3 voisines vivantes
        etatSuivant = (nbVoisinesVivantes == 2 || nbVoisinesVivantes == 3);
    } else {
        // Règle : Une cellule morte devient vivante avec exactement 3 voisines vivantes
        etatSuivant = (nbVoisinesVivantes == 3);
    }
}

// Implémentation de la méthode pour mettre à jour l'état
void CelluleStandard::mettreAJour() {
    // Appelle la méthode mettreAJour de la classe de base
    Cellule::mettreAJour();
}
