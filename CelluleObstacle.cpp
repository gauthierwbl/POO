#include "CelluleObstacle.h"
#include <iostream>

CelluleObstacle::CelluleObstacle() : Cellule() {
    etatActuel = true; // Les obstacles sont toujours considérés comme "vivants"
}

void CelluleObstacle::calculerEtatSuivant(int voisinesVivantes) {
    // L'état suivant d'un obstacle est toujours le même
    etatSuivant = etatActuel;
}

