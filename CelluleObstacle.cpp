#include "CelluleObstacle.h"
#include <iostream>

// Constructeur de la classe CelluleObstacle
// Appelle le constructeur de la classe de base Cellule avec l'état initial à faux (false)
CelluleObstacle::CelluleObstacle() : Cellule(false) {}

// Implémentation de la méthode pour calculer l'état suivant
void CelluleObstacle::calculerEtatSuivant(int /* nbVoisinesVivantes */) {
    // Les obstacles ne changent jamais d'état, donc l'état suivant est toujours faux (false)
    etatSuivant = false;
}

// Implémentation de la méthode pour mettre à jour l'état
void CelluleObstacle::mettreAJour() {
    // Les obstacles ne changent pas d'état, donc l'état actuel reste faux (false)
    etatActuel = false;
}
