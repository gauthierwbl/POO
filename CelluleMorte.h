#ifndef CELLULEMORTE_H
#define CELLULEMORTE_H

#include "Cellule.h"

class CelluleMorte : public Cellule {
public:
    CelluleMorte();  // Constructeur
    bool getEtatActuel() const override;  // Retourne l'état actuel
    void setEtatActuel(bool etat) override;  // Modifie l'état actuel
};

#endif // CELLULEMORTE_H
