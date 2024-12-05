#ifndef CELLULE_OBSTACLE_H
#define CELLULE_OBSTACLE_H

#include "Cellule.h" // Inclusion de la classe de base Cellule

// Définition de la classe CelluleObstacle, dérivée de Cellule
class CelluleObstacle : public Cellule {
public:
    // Constructeur de la classe CelluleObstacle
    CelluleObstacle();

    // Implémentation de la méthode virtuelle pure pour calculer l'état suivant
    void calculerEtatSuivant(int nbVoisinesVivantes) override;

    // Implémentation de la méthode virtuelle pour mettre à jour l'état
    void mettreAJour() override;
};

#endif 
