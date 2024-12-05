#include "Grille.h"
#include <iostream>

Grille::Grille(int largeur, int hauteur, bool torique)
    : largeur(largeur), hauteur(hauteur), torique(torique), cellules(largeur, std::vector<Cellule*>(hauteur, nullptr)) {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y] = new CelluleMorte();  // Initialisation avec des cellules mortes
        }
    }
}

Grille::~Grille() {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y];
        }
    }
}

int Grille::coordonneeTorique(int coord, int max) const {
    return (coord + max) % max;
}

int Grille::compterVoisinesVivantes(int x, int y) const {
    static const int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                      {0, -1}, {0, 1},
                                      {1, -1}, {1, 0}, {1, 1}};
    int count = 0;

    for (const auto& offset : offsets) {
        int nx = x + offset[0];
        int ny = y + offset[1];

        if (torique) {
            nx = coordonneeTorique(nx, largeur);
            ny = coordonneeTorique(ny, hauteur);
        } else if (nx < 0 || ny < 0 || nx >= largeur || ny >= hauteur) {
            continue;
        }

        if (cellules[nx][ny]->getEtatActuel()) {
            ++count;
        }
    }

    return count;
}

void Grille::calculerEtatsSuivants() {
    // Création d'une grille temporaire pour stocker les nouveaux états
    std::vector<std::vector<Cellule*>> nouvellesCellules(largeur, std::vector<Cellule*>(hauteur, nullptr));

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            int nbVoisinesVivantes = compterVoisinesVivantes(x, y);
            // Si la cellule est morte, elle devient vivante si elle a exactement 3 voisines vivantes
            if (!cellules[x][y]->getEtatActuel()) {
                if (nbVoisinesVivantes == 3) {
                    nouvellesCellules[x][y] = new CelluleVivante();  // La cellule devient vivante
                } else {
                    nouvellesCellules[x][y] = new CelluleMorte();  // La cellule reste morte
                }
            } else {
                // Si la cellule est vivante, elle reste vivante si elle a 2 ou 3 voisines vivantes
                if (nbVoisinesVivantes == 2 || nbVoisinesVivantes == 3) {
                    nouvellesCellules[x][y] = new CelluleVivante();  // La cellule reste vivante
                } else {
                    nouvellesCellules[x][y] = new CelluleMorte();  // La cellule meurt
                }
            }
        }
    }

    // Remplace les anciennes cellules par les nouvelles cellules
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y];
            cellules[x][y] = nouvellesCellules[x][y];
        }
    }
}

void Grille::mettreAJour() {
    // Pas besoin de mettre à jour ici, car chaque cellule gère son état indépendamment
}

void Grille::afficherConsole() const {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            std::cout << (cellules[x][y]->getEtatActuel() ? '1' : '0') << " ";
        }
        std::cout << '\n';
    }
}

void Grille::setCellule(int x, int y, Cellule* cellule) {
    if (torique) {
        x = coordonneeTorique(x, largeur);
        y = coordonneeTorique(y, hauteur);
    }

    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        delete cellules[x][y];
        cellules[x][y] = cellule;
    }
}

Cellule* Grille::getCellule(int x, int y) const {
    if (torique) {
        x = coordonneeTorique(x, largeur);
        y = coordonneeTorique(y, hauteur);
    }

    return cellules[x][y];
}

void Grille::ajouterMotifDansGrille(const Motif& motif) {
    // Implémentation de l'ajout d'un motif dans la grille
}
