#ifndef CELLULE_H
#define CELLULE_H

// Définition de la classe Cellule
class Cellule {
protected:
    bool etatActuel;  // État actuel de la cellule : vivante (true) ou morte (false)
    bool etatSuivant; // État à venir de la cellule : vivante ou morte
    bool etatPrecedent; // Nouvel attribut pour l'état précédent

public:
    // Constructeur de la classe Cellule
    // Permet d'initialiser l'état de la cellule, par défaut à morte (false)
    Cellule(bool etatInitial = false);

    // Accesseur pour obtenir l'état actuel de la cellule
    bool getEtatActuel() const;

    // Mutateur pour définir l'état actuel de la cellule
    void setEtatActuel(bool etat);

    // Accesseur pour obtenir l'état suivant de la cellule
    bool getEtatSuivant() const;

    // Mutateur pour définir l'état suivant de la cellule
    void setEtatSuivant(bool etat);

    // Accesseur pour obtenir l'état précédent de la cellule
    bool getEtatPrecedent() const; // Nouvel accesseur pour l'état précédent

    // Mutateur pour définir l'état précédent de la cellule
    void setEtatPrecedent(bool etat); // Nouvel mutateur pour l'état précédent

    // Méthode virtuelle pure qui sera définie dans les classes dérivées
    virtual void calculerEtatSuivant(int nbVoisinesVivantes) = 0;

    // Méthode virtuelle pure pour mettre à jour l'état actuel de la cellule
    virtual void mettreAJour() = 0;

    // Destructeur virtuel pour assurer la destruction correcte des classes dérivées
    virtual ~Cellule();
};

#endif
