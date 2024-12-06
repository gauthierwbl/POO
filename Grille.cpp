#include "Grille.h"
#include <iostream>

Grille::Grille(int largeur, int hauteur, bool torique)
    : largeur(largeur), hauteur(hauteur), torique(torique), cellules(largeur, std::vector<Cellule*>(hauteur, nullptr)), etatsSuivants(largeur, std::vector<bool>(hauteur, false)) {
    // Initialisation de la grille avec des cellules mortes
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y] = new CelluleMorte();  // Chaque cellule est initialisée comme morte
        }
    }
}

Grille::~Grille() {
    // Libération de la mémoire allouée pour chaque cellule
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y];
        }
    }
}

int Grille::coordonneeTorique(int coord, int max) const {
    return (coord + max) % max; // Retourne la coordonnée ajustée pour la toricité
}

int Grille::compterVoisinesVivantes(int x, int y) const {
    int count = 0;

    // Parcours des voisins autour de la cellule (x, y)
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule centrale (x, y)

            int nx = x + dx;
            int ny = y + dy;

            // Gestion des coordonnées toriques
            if (torique) {
                nx = coordonneeTorique(nx, largeur);
                ny = coordonneeTorique(ny, hauteur);
            } else if (nx < 0 || ny < 0 || nx >= largeur || ny >= hauteur) {
                continue; // Ignore les voisins hors limites si non torique
            }

            // Incrémente le compteur si la cellule voisine est vivante
            if (cellules[nx][ny]->getEtatActuel()) {
                ++count;
            }
        }
    }

    return count;
}

void Grille::calculerEtatSuivant(int x, int y) {
    int nbVoisinesVivantes = compterVoisinesVivantes(x, y);

    // Calculer l'état suivant pour chaque cellule
    if (!cellules[x][y]->getEtatActuel()) {
        // Cellule morte devient vivante si elle a exactement 3 voisines vivantes
        if (nbVoisinesVivantes == 3) {
            etatsSuivants[x][y] = true;
        } else {
            etatsSuivants[x][y] = false;
        }
    } else {
        // Cellule vivante reste vivante si elle a 2 ou 3 voisines vivantes, sinon elle meurt
        if (nbVoisinesVivantes == 2 || nbVoisinesVivantes == 3) {
            etatsSuivants[x][y] = true;
        } else {
            etatsSuivants[x][y] = false;
        }
    }
}

void Grille::next() {
    // Calculer les états suivants pour toutes les cellules
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            calculerEtatSuivant(x, y);
        }
    }

    // Appliquer les nouveaux états aux cellules
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            // Si l'état suivant est vrai, la cellule devient vivante
            if (etatsSuivants[x][y]) {
                if (dynamic_cast<CelluleMorte*>(cellules[x][y])) {
                    delete cellules[x][y];
                    cellules[x][y] = new CelluleVivante();
                }
            } else {
                // Sinon, elle devient morte
                if (dynamic_cast<CelluleVivante*>(cellules[x][y])) {
                    delete cellules[x][y];
                    cellules[x][y] = new CelluleMorte();
                }
            }
        }
    }
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
