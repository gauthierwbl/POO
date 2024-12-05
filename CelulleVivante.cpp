#include "CelluleVivante.h"
#include <iostream>

// Constructeur de la classe CelluleVivante
// Une cellule vivante est initialisée avec un état "vivant" (true)
CelluleVivante::CelluleVivante() : Cellule(true) {}

// Calculer l'état suivant d'une cellule vivante
// Une cellule vivante reste vivante si elle a 2 ou 3 voisines vivantes, sinon elle meurt
void CelluleVivante::calculerEtatSuivant(int nbVoisinesVivantes) {
    if (nbVoisinesVivantes == 2 || nbVoisinesVivantes == 3) {
        setEtatSuivant(true);
    } else {
        setEtatSuivant(false);
    }
}

// Mettre à jour l'état actuel de la cellule vivante
void CelluleVivante::mettreAJour() {
    setEtatActuel(getEtatSuivant());
}
