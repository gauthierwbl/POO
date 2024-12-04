#ifndef CELLULE_STANDARD_H
#define CELLULE_STANDARD_H

#include "Cellule.h"

class CelluleStandard : public Cellule {
public:
    CelluleStandard();
    ~CelluleStandard() override = default;

    void calculerEtatSuivant(int voisinesVivantes) override;
};

#endif
