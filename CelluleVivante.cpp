#include "CelluleVivante.h"

CelluleVivante::CelluleVivante() {
    etatActuel = true;  // Une cellule vivante est initialement vivante
}

bool CelluleVivante::getEtatActuel() const {
    return etatActuel;
}

void CelluleVivante::setEtatActuel(bool etat) {
    etatActuel = etat;
}
