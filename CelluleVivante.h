#ifndef CELLULE_VIVANTE_H
#define CELLULE_VIVANTE_H

#include "Cellule.h"

// Définition de la classe CelluleVivante, dérivée de la classe Cellule
class CelluleVivante : public Cellule {
public:
    // Constructeur de la classe CelluleVivante
    CelluleVivante();

    // Calculer l'état suivant pour une cellule vivante (elle peut rester vivante ou mourir)
    void calculerEtatSuivant(int nbVoisinesVivantes) override;

    // Mettre à jour l'état actuel de la cellule vivante
    void mettreAJour() override;
};

#endif
