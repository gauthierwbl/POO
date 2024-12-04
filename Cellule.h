#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
protected:
    bool etatActuel;   // État actuel de la cellule (vivante ou morte)
    bool etatSuivant;  // État suivant calculé pour la cellule

public:
    Cellule();
    virtual ~Cellule() = default;

    bool getEtatActuel() const;
    void setEtatActuel(bool etat);

    virtual void calculerEtatSuivant(int voisinesVivantes) = 0; // Méthode pure virtuelle
    void mettreAJour();
};

#endif
