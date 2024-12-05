#include "Grille.h"
#include "CelluleStandard.h" // Inclure les différents types de cellules si nécessaire
#include <iostream>

Grille::Grille(int largeur, int hauteur, bool torique)
    : largeur(largeur), hauteur(hauteur), torique(torique), cellules(largeur, std::vector<Cellule*>(hauteur, nullptr)) {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y] = new CelluleStandard();
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
            // Crée une nouvelle cellule avec l'état suivant calculé
            nouvellesCellules[x][y] = new CelluleStandard();
            nouvellesCellules[x][y]->calculerEtatSuivant(nbVoisinesVivantes);
        }
    }

    // Remplace les anciennes cellules par les nouvelles cellules
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y];  // Libère la mémoire de l'ancienne cellule
            cellules[x][y] = nouvellesCellules[x][y];  // Met à jour avec la nouvelle cellule
        }
    }
}


void Grille::mettreAJour() {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y]->mettreAJour();
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
        delete cellules[x][y]; // Libère la mémoire de la cellule précédente
        cellules[x][y] = cellule;
    }
}

Cellule* Grille::getCellule(int x, int y) const {
    if (torique) {
        x = coordonneeTorique(x, largeur);
        y = coordonneeTorique(y, hauteur);
    }

    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        return cellules[x][y];
    }
    return nullptr;

}

void Grille::ajouterMotifDansGrille(const Motif& motif) {
    // Suppose que tu as les coordonnées de départ pour insérer le motif
    for (int y = 0; y < motif.getHauteur(); ++y) {
        for (int x = 0; x < motif.getLargeur(); ++x) {
            // Vérifie si la cellule du motif est vivante et mets à jour la cellule correspondante dans la grille
            if (motif.getCellules()[y][x]) {
                cellules[y][x]->setEtatActuel(true);  // Remplacer setEtat par setEtatActuel
            }
        }
    }
}












