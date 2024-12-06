#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

class CelluleVivante : public Cellule {
public:
    CelluleVivante();  // Constructeur
    bool getEtatActuel() const override;  // Retourne l'état actuel
    void setEtatActuel(bool etat) override;  // Modifie l'état actuel
};

#endif // CELLULEVIVANTE_H
