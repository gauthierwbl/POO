#include "CelluleMorte.h"

CelluleMorte::CelluleMorte() {
    etatActuel = false;  // Une cellule morte est initialement morte
}

bool CelluleMorte::getEtatActuel() const {
    return etatActuel;
}

void CelluleMorte::setEtatActuel(bool etat) {
    etatActuel = etat;
}
