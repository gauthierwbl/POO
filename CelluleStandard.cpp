#include "CelluleStandard.h"
#include <iostream>

CelluleStandard::CelluleStandard() : Cellule() {}

void CelluleStandard::calculerEtatSuivant(int voisinesVivantes) {
    // Règle classique du jeu de la vie
    if (etatActuel) {
        etatSuivant = (voisinesVivantes == 2 || voisinesVivantes == 3);
    } else {
        etatSuivant = (voisinesVivantes == 3);
    }
}

