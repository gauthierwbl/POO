// Grille.h
#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include "Motif.h"
#include <vector>

class Grille {
private:
    int largeur;
    int hauteur;
    bool torique;
    std::vector<std::vector<Cellule*>> cellules;

    int coordonneeTorique(int coord, int max) const;

public:
    Grille(int largeur, int hauteur, bool torique);
    ~Grille();

    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }

    void calculerEtatsSuivants();
    void mettreAJour();
    void afficherConsole() const;

    int compterVoisinesVivantes(int x, int y) const;

    void setCellule(int x, int y, Cellule* cellule);
    Cellule* getCellule(int x, int y) const;
    

    // Ajout de la méthode 'ajouterMotifDansGrille' dans la déclaration de la classe Grille
    void ajouterMotifDansGrille(const Motif& motif);
};

#endif
