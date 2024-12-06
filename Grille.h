#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include "CelluleMorte.h"
#include "CelluleVivante.h"
#include <vector>

class Grille {
private:
    int largeur; // Largeur de la grille
    int hauteur; // Hauteur de la grille
    bool torique; // Indique si la grille est torique
    std::vector<std::vector<Cellule*>> cellules; // Matrice de pointeurs vers les cellules
    std::vector<std::vector<bool>> etatsSuivants; // Matrice pour stocker les états suivants des cellules

    // Méthode utilitaire pour gérer les coordonnées dans une grille torique
    int coordonneeTorique(int coord, int max) const;

    // Méthode pour calculer l'état suivant d'une cellule donnée
    void calculerEtatSuivant(int x, int y);

public:
    Grille(int largeur, int hauteur, bool torique);
    ~Grille();

    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }

    // Méthodes pour l'évolution de la grille
    void next();                        // Calcule les états suivants des cellules
    void afficherConsole() const;       // Affiche la grille dans la console

    // Compte le nombre de cellules vivantes voisines d'une cellule donnée
    int compterVoisinesVivantes(int x, int y) const;

    // Manipuler les cellules de la grille
    void setCellule(int x, int y, Cellule* cellule);
    Cellule* getCellule(int x, int y) const;
};

#endif // GRILLE_H
