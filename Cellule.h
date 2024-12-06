#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
protected:
    bool etatActuel;  // État de la cellule (vivante ou morte)

public:
    virtual bool getEtatActuel() const = 0;  // Retourne l'état actuel de la cellule
    virtual void setEtatActuel(bool etat) = 0;  // Modifie l'état actuel de la cellule
    virtual ~Cellule() = default;  // Destructeur virtuel
};

#endif // CELLULE_H
