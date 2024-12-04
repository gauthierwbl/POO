#ifndef CELLULE_OBSTACLE_H
#define CELLULE_OBSTACLE_H

#include "Cellule.h"

class CelluleObstacle : public Cellule {
public:
    CelluleObstacle();
    ~CelluleObstacle() override = default;

    void calculerEtatSuivant(int voisinesVivantes) override;
};

#endif
