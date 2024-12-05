#ifndef MOTIF_H
#define MOTIF_H

#include <string>   // Inclusion de la bibliothèque pour les chaînes de caractères
#include <vector>   // Inclusion de la bibliothèque pour les vecteurs

// Déclaration de la classe Motif
class Motif {
private:
    std::string nom;  // Le nom du motif (Glider, Bloc, Oscillateur, etc.)
    int largeur;      // Largeur du motif
    int hauteur;      // Hauteur du motif
    std::vector<std::vector<bool>> cellules;  // Grille de cellules représentant le motif

public:
    // Constructeur de la classe Motif
    Motif(std::string nom, int largeur, int hauteur);

    // Getters pour accéder aux attributs privés
    std::string getNom() const; // Retourne le nom du motif
    int getLargeur() const;      // Retourne la largeur du motif
    int getHauteur() const;      // Retourne la hauteur du motif
    std::vector<std::vector<bool>> getCellules() const; // Retourne la grille de cellules

    // Méthode pour vérifier si une cellule (x, y) fait partie du motif
    bool estDansMotif(int x, int y) const;

    // Méthodes statiques pour créer des motifs prédéfinis
    static Motif createGlider();      // Crée un motif Glider
    static Motif createBloc();         // Crée un motif Bloc
    static Motif createOscillateur();  // Crée un motif Oscillateur
};

#endif // Fin de la protection d'inclusion
