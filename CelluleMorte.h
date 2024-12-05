#ifndef CELLULE_MORTE_H
#define CELLULE_MORTE_H

#include "Cellule.h"

// Définition de la classe CelluleMorte, dérivée de la classe Cellule
class CelluleMorte : public Cellule {
public:
    // Constructeur de la classe CelluleMorte
    CelluleMorte();

    // La cellule morte ne change pas d'état suivant, elle reste morte
    void calculerEtatSuivant(int nbVoisinesVivantes) override;

    // La cellule morte ne met pas à jour son état
    void mettreAJour() override;
};

#endif
