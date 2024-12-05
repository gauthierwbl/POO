#ifndef CELLULE_STANDARD_H
#define CELLULE_STANDARD_H

#include "Cellule.h" // Inclusion de la classe de base Cellule

// Définition de la classe CelluleStandard, dérivée de Cellule
class CelluleStandard : public Cellule {
public:
    // Constructeur de la classe CelluleStandard
    // Permet d'initialiser l'état de la cellule, par défaut à morte (false)
    CelluleStandard(bool etatInitial = false);

    // Implémentation de la méthode virtuelle pour calculer l'état suivant
    void calculerEtatSuivant(int nbVoisinesVivantes) override;

    // Implémentation de la méthode virtuelle pour mettre à jour l'état
    void mettreAJour() override;
};

#endif 
