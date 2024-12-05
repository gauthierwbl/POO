#include "FichierTexte.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <random>  // Pour la génération aléatoire

// Méthodes utilitaires pour manipuler les fichiers texte
std::string FichierTexte::lireFichierTexte(const std::string& chemin) {
    std::ifstream fichier(chemin);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + chemin);
    }

    std::ostringstream contenu;
    contenu << fichier.rdbuf();
    return contenu.str();
}

void FichierTexte::ecrireFichierTexte(const std::string& chemin, const std::string& contenu) {
    std::ofstream fichier(chemin);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier pour écriture : " + chemin);
    }

    fichier << contenu;
}

// Charger une grille depuis un fichier texte
void FichierTexte::charger(const std::string& chemin, Grille& grille) {
    std::string contenu = lireFichierTexte(chemin);
    std::istringstream flux(contenu);

    int largeur = grille.getLargeur();
    int hauteur = grille.getHauteur();

    int y = 0;
    std::string ligne;
    while (std::getline(flux, ligne) && y < hauteur) {
        for (int x = 0; x < largeur && x < static_cast<int>(ligne.size()); ++x) {
            Cellule* nouvelleCellule = nullptr;

            // Création de la cellule en fonction des caractères du fichier
            if (ligne[x] == '1') {
                nouvelleCellule = new CelluleVivante();  // Remplacer CelluleStandard par CelluleVivante
                nouvelleCellule->setEtatActuel(true);
            } else {
                nouvelleCellule = new CelluleMorte();  // Remplacer CelluleObstacle par CelluleMorte
                nouvelleCellule->setEtatActuel(false);
            }

            // Remplace la cellule existante pour éviter les fuites mémoire
            grille.setCellule(x, y, nouvelleCellule);
        }
        ++y;
    }
}

// Sauvegarder une grille dans un fichier texte
void FichierTexte::sauvegarder(const std::string& chemin, const Grille& grille) {
    int largeur = grille.getLargeur();
    int hauteur = grille.getHauteur();

    std::ostringstream contenu;

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            contenu << (grille.getCellule(x, y)->getEtatActuel() ? '1' : '0');
        }
        contenu << '\n';
    }

    ecrireFichierTexte(chemin, contenu.str());
}

// Créer une grille aléatoire et la sauvegarder dans un fichier texte
void FichierTexte::genererGrilleAleatoire(const std::string& chemin, int largeur, int hauteur) {
    std::ofstream fichier(chemin);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible de créer le fichier : " + chemin);
    }

    std::random_device rd;  // Pour obtenir une graine aléatoire
    std::mt19937 gen(rd()); // Générateur de nombres aléatoires
    std::uniform_int_distribution<> distrib(0, 1); // Distribution uniforme entre 0 et 1

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            // Générer aléatoirement '1' ou '0' pour chaque cellule
            fichier << distrib(gen);
        }
        fichier << '\n';  // Ajouter un retour à la ligne à la fin de chaque ligne de la grille
    }

    std::cout << "Fichier généré avec une grille aléatoire : " << chemin << std::endl;
}

