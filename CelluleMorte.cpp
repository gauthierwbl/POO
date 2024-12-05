#include "CelluleMorte.h"
#include <iostream>

// Constructeur de la classe CelluleMorte
// Une cellule morte est initialisée avec un état "morte" (false)
CelluleMorte::CelluleMorte() : Cellule(false) {}

// Calculer l'état suivant d'une cellule morte (elle ne devient jamais vivante)
void CelluleMorte::calculerEtatSuivant(int nbVoisinesVivantes) {
    // Une cellule morte ne devient vivante que si elle a exactement 3 voisines vivantes
    if (nbVoisinesVivantes == 3) {
        setEtatSuivant(true);
    } else {
        setEtatSuivant(false);
    }
}

// La cellule morte ne change pas son état
void CelluleMorte::mettreAJour() {
    setEtatActuel(getEtatSuivant());
}
