#ifndef CELLULE_H
#define CELLULE_H

// Définition de la classe Cellule
class Cellule {
protected:
    bool etatActuel;  // État actuel de la cellule : vivante (true) ou morte (false)
    bool etatSuivant; // État à venir de la cellule : vivante ou morte

public:
    // Constructeur de la classe Cellule
    // Permet d'initialiser l'état de la cellule, par défaut à morte (false)
    Cellule(bool etatInitial = false);

    // Accesseur pour obtenir l'état actuel de la cellule
    bool getEtatActuel() const;

    // Mutateur pour définir l'état actuel de la cellule
    void setEtatActuel(bool etat);

    // Méthode virtuelle pure pour calculer l'état suivant
    // Doit être implémentée par les classes dérivées
    virtual void calculerEtatSuivant(int nbVoisinesVivantes) = 0;

    // Méthode pour mettre à jour l'état de la cellule
    // Peut être redéfinie dans les classes dérivées
    virtual void mettreAJour();

    // Destructeur virtuel pour assurer la destruction correcte des classes dérivées
    virtual ~Cellule();
};

#endif 
