#include "Grille.h"
#include <iostream>

// Constructeur de la classe Grille
Grille::Grille(int largeur, int hauteur, bool torique)
    : largeur(largeur), hauteur(hauteur), torique(torique), cellules(largeur, std::vector<Cellule*>(hauteur, nullptr)) {
    // Initialisation de la grille avec des cellules mortes
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y] = new CelluleMorte();  // Chaque cellule est initialisée comme morte
        }
    }
}

// Destructeur de la classe Grille
Grille::~Grille() {
    // Libération de la mémoire allouée pour chaque cellule
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y];
        }
    }
}

// Méthode pour gérer les coordonnées dans une grille torique
int Grille::coordonneeTorique(int coord, int max) const {
    return (coord + max) % max; // Retourne la coordonnée ajustée pour la toricité
}

// Compte le nombre de cellules vivantes voisines d'une cellule donnée
int Grille::compterVoisinesVivantes(int x, int y) const {
    // Définition des décalages pour les 8 voisins
    static const int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                       {0, -1},         {0, 1},
                                       {1, -1}, {1, 0}, {1, 1}};
    int count = 0; // Compteur de cellules vivantes

    // Vérification des voisins
    for (const auto& offset : offsets) {
        int nx = x + offset[0]; // Coordonnée x du voisin
        int ny = y + offset[1]; // Coordonnée y du voisin

        // Gestion des coordonnées torique
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

    return count; // Retourne le nombre de voisines vivantes
}

// Calcule les états suivants des cellules de la grille
void Grille::calculerEtatsSuivants() {
    // Création de la grille temporaire (grilleAChange) pour stocker les nouveaux états
    std::vector<std::vector<Cellule*>> grilleAChange(largeur, std::vector<Cellule*>(hauteur, nullptr));

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            int nbVoisinesVivantes = compterVoisinesVivantes(x, y); // Compte les voisines vivantes
            // Si la cellule est morte, elle devient vivante si elle a exactement 3 voisines vivantes
            if (!cellules[x][y]->getEtatActuel()) {
                if (nbVoisinesVivantes == 3) {
                    grilleAChange[x][y] = new CelluleVivante();  // La cellule devient vivante
                } else {
                    grilleAChange[x][y] = new CelluleMorte();  // La cellule reste morte
                }
            } else {
                // Si la cellule est vivante, elle reste vivante si elle a 2 ou 3 voisines vivantes
                if (nbVoisinesVivantes == 2 || nbVoisinesVivantes == 3) {
                    grilleAChange[x][y] = new CelluleVivante();  // La cellule reste vivante
                } else {
                    grilleAChange[x][y] = new CelluleMorte();  // La cellule meurt
                }
            }
        }
    }

    // Remplace les anciennes cellules par les nouvelles cellules dans la grille principale
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            delete cellules[x][y]; // Libère l'ancienne cellule
            cellules[x][y] = grilleAChange[x][y]; // Met à jour avec la nouvelle cellule
        }
    }
}

// Méthode pour mettre à jour la grille (actuellement vide)
void Grille::mettreAJour() {
    // Pas besoin de mise à jour ici, car chaque cellule gère son état indépendamment
}

// Affiche la grille dans la console
void Grille::afficherConsole() const {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            std::cout << (cellules[x][y]->getEtatActuel() ? '1' : '0') << " "; // Affiche '1' pour vivante, '0' pour morte
        }
        std::cout << '\n'; // Retour à la ligne après chaque ligne de la grille
    }
}

// Définit une cellule à une position donnée
void Grille::setCellule(int x, int y, Cellule* cellule) {
    // Gestion des coordonnées torique
    if (torique) {
        x = coordonneeTorique(x, largeur);
        y = coordonneeTorique(y, hauteur);
    }

    // Vérifie les limites et met à jour la cellule
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        delete cellules[x][y]; // Libère l'ancienne cellule
        cellules[x][y] = cellule; // Met à jour avec la nouvelle cellule
    }
}

// Obtient la cellule à une position donnée
Cellule* Grille::getCellule(int x, int y) const {
    // Gestion des coordonnées torique
    if (torique) {
        x = coordonneeTorique(x, largeur);
        y = coordonneeTorique(y, hauteur);
    }

    return cellules[x][y]; // Retourne la cellule à la position donnée
}



