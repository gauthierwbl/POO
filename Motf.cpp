#include "Motif.h"
#include <iostream>

// Constructeur
Motif::Motif(std::string nom, int largeur, int hauteur)
    : nom(nom), largeur(largeur), hauteur(hauteur), cellules(hauteur, std::vector<bool>(largeur, false)) {}

// Getters
std::string Motif::getNom() const {
    return nom;
}

int Motif::getLargeur() const {
    return largeur;
}

int Motif::getHauteur() const {
    return hauteur;
}

std::vector<std::vector<bool>> Motif::getCellules() const {
    return cellules;  // Retourne les cellules du motif
}

// Méthode pour vérifier si une cellule (x, y) fait partie du motif
bool Motif::estDansMotif(int x, int y) const {
    if (x < 0 || x >= largeur || y < 0 || y >= hauteur) {
        return false;  // Si (x, y) est en dehors des limites
    }
    return cellules[y][x];  // Retourne si la cellule est activée (true)
}

// Méthodes statiques pour créer des motifs prédéfinis

Motif Motif::createGlider() {
    // Création du Glider : un petit motif mobile dans le jeu de la vie
    Motif glider("Glider", 5, 5);
    glider.cellules[1][0] = true;
    glider.cellules[2][1] = true;
    glider.cellules[0][2] = true;
    glider.cellules[1][2] = true;
    glider.cellules[2][2] = true;
    return glider;
}

Motif Motif::createBloc() {
    // Création du Bloc : un motif stable
    Motif bloc("Bloc", 4, 4);
    bloc.cellules[1][1] = true;
    bloc.cellules[1][2] = true;
    bloc.cellules[2][1] = true;
    bloc.cellules[2][2] = true;
    return bloc;
}

Motif Motif::createOscillateur() {
    // Création d'un Oscillateur : un motif oscillant, par exemple le "blinker"
    Motif oscillateur("Oscillateur", 3, 3);
    oscillateur.cellules[1][0] = true;
    oscillateur.cellules[1][1] = true;
    oscillateur.cellules[1][2] = true;
    return oscillateur;
}
