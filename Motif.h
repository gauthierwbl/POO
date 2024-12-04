#ifndef MOTIF_H
#define MOTIF_H

#include <string>
#include <vector>

class Motif {
private:
    std::string nom;  // Le nom du motif (Glider, Bloc, Oscillateur, etc.)
    int largeur, hauteur;  // Dimensions du motif
    std::vector<std::vector<bool>> cellules;  // Grille de cellules représentant le motif

public:
    // Constructeur
    Motif(std::string nom, int largeur, int hauteur);

    // Getters
    std::string getNom() const;
    int getLargeur() const;
    int getHauteur() const;

    std::vector<std::vector<bool>> getCellules() const;

    // Méthode pour vérifier si une cellule (x, y) fait partie du motif
    bool estDansMotif(int x, int y) const;

    // Définir les méthodes statiques pour créer des motifs prédéfinis
    static Motif createGlider();
    static Motif createBloc();
    static Motif createOscillateur();
};

#endif // MOTIF_H
