#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"              // Inclusion de la classe Cellule
#include "CelluleMorte.h"         // Inclusion de la classe CelluleMorte
#include "CelluleVivante.h"       // Inclusion de la classe CelluleVivante
#include "Motif.h"                // Inclusion de la classe Motif
#include <vector>                // Inclusion de la bibliothèque vector pour utiliser des vecteurs

// Déclaration de la classe Grille
class Grille {
private:
    int largeur;                                 // Largeur de la grille
    int hauteur;                                 // Hauteur de la grille
    bool torique;                                // Indique si la grille est torique
    std::vector<std::vector<Cellule*>> cellules; // Matrice de pointeurs vers les cellules

    // Méthode utilitaire pour gérer les coordonnées dans une grille torique
    int coordonneeTorique(int coord, int max) const;

public:
    // Constructeur de la classe Grille
    Grille(int largeur, int hauteur, bool torique);
    // Destructeur de la classe Grille
    ~Grille();

    // Accesseurs pour obtenir la largeur et la hauteur de la grille
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }

    // Méthodes pour gérer l'évolution de la grille
    void calculerEtatsSuivants(); // Calcule les états suivants des cellules
    void mettreAJour();            // Met à jour la grille avec les nouveaux états
    void afficherConsole() const;  // Affiche la grille dans la console

    // Compte le nombre de cellules vivantes voisines d'une cellule donnée
    int compterVoisinesVivantes(int x, int y) const;

    // Méthodes pour manipuler les cellules de la grille
    void setCellule(int x, int y, Cellule* cellule); // Définit une cellule à une position donnée
    Cellule* getCellule(int x, int y) const;         // Obtient la cellule à une position donnée

    // Ajout de la méthode 'ajouterMotifDansGrille'
    void ajouterMotifDansGrille(const Motif& motif); // Ajoute un motif à la grille

};

#endif // Fin de la protection d'inclusion
