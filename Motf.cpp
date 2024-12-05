#include "Motif.h"
#include <iostream>

// Constructeur de la classe Motif
Motif::Motif(std::string nom, int largeur, int hauteur)
    : nom(nom), largeur(largeur), hauteur(hauteur), 
      cellules(hauteur, std::vector<bool>(largeur, false)) {
    // Initialise le motif avec le nom, la largeur, la hauteur et une grille de cellules (initialisées à false)
}

// Getters
std::string Motif::getNom() const {
    return nom; // Retourne le nom du motif
}

int Motif::getLargeur() const {
    return largeur; // Retourne la largeur du motif
}

int Motif::getHauteur() const {
    return hauteur; // Retourne la hauteur du motif
}

std::vector<std::vector<bool>> Motif::getCellules() const {
    return cellules; // Retourne les cellules du motif
}

// Méthode pour vérifier si une cellule (x, y) fait partie du motif
bool Motif::estDansMotif(int x, int y) const {
    if (x < 0 || x >= largeur || y < 0 || y >= hauteur) {
        return false; // Vérifie si (x, y) est en dehors des limites
    }
    return cellules[y][x]; // Retourne si la cellule est activée (true)
}

// Méthodes statiques pour créer des motifs prédéfinis

Motif Motif::createGlider() {
    // Création du Glider : un petit motif mobile dans le jeu de la vie
    Motif glider("Glider", 5, 5);
    glider.cellules[1][0] = true; // Positionne les cellules actives pour former un Glider
    glider.cellules[2][1] = true;
    glider.cellules[0][2] = true;
    glider.cellules[1][2] = true;
    glider.cellules[2][2] = true;
    return glider; // Retourne le motif Glider
}

Motif Motif::createBloc() {
    // Création du Bloc : un motif stable
    Motif bloc("Bloc", 4, 4);
    bloc.cellules[1][1] = true; // Positionne les cellules actives pour former un Bloc
    bloc.cellules[1][2] = true;
    bloc.cellules[2][1] = true;
    bloc.cellules[2][2] = true;
    return bloc; // Retourne le motif Bloc
}

Motif Motif::createOscillateur() {
    // Création d'un Oscillateur : un motif oscillant, par exemple le "blinker"
    Motif oscillateur("Oscillateur", 3, 3);
    oscillateur.cellules[1][0] = true; // Positionne les cellules actives pour former un Oscillateur
    oscillateur.cellules[1][1] = true;
    oscillateur.cellules[1][2] = true;
    return oscillateur; // Retourne le motif Oscillateur
}
