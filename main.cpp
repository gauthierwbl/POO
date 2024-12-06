#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "FichierTexte.h"
#include "Grille.h"
#include "Cellule.h"

int main() {
    // Initialisation des paramètres
    int largeur = 20, hauteur = 20, nombreIterations = 20;
    bool torique = false;  // Grille torique

    // Création des objets principaux
    Simulation simulation(largeur, hauteur, torique, nombreIterations);
    FichierTexte fichierTexte;  // Création d'une instance de FichierTexte

    // Gestion du fichier d'état initial
    std::string cheminFichier = "GrilleInitiale.txt";
    std::ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cout << "Le fichier " << cheminFichier << " n'existe pas. Génération d'une grille aléatoire.\n";
        try {
            fichierTexte.genererGrilleAleatoire(cheminFichier, largeur, hauteur);  // Utilisation de l'instance
            std::cout << "Grille générée et sauvegardée dans " << cheminFichier << ".\n";
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la génération de la grille : " << e.what() << std::endl;
            return 1;
        }
    }

    try {
        fichierTexte.charger(cheminFichier, *simulation.getGrille());  // Utilisation de l'instance
        std::cout << "État initial chargé depuis " << cheminFichier << ".\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement de la grille : " << e.what() << std::endl;
        return 1;
    }

    // Choix du mode d'affichage
    char choixInterface;
    std::cout << "Voulez-vous utiliser l'interface graphique (G) ou la console (C) ? ";
    std::cin >> choixInterface;

    int iterationActuelle = 0;

    if (choixInterface == 'G' || choixInterface == 'g') {
        // Interface graphique avec SFML
        sf::RenderWindow window(sf::VideoMode(largeur * 20, hauteur * 20), "Jeu de la Vie");
        sf::RectangleShape cellule(sf::Vector2f(18, 18));

        while (window.isOpen() && iterationActuelle < nombreIterations) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                    simulation.demarrer();
                    iterationActuelle++;
                }
            }

            window.clear(sf::Color::White);
            for (int x = 0; x < largeur; x++) {
                for (int y = 0; y < hauteur; y++) {
                    cellule.setPosition(x * 20 + 1, y * 20 + 1);
                    cellule.setFillColor(simulation.getGrille()->getCellule(x, y)->getEtatActuel() ? sf::Color::Green : sf::Color::Black);
                    window.draw(cellule);
                }
            }
            window.display();
        }
    } else {
        // Mode console
        std::cout << "Simulation en mode console...\n";
        for (int i = 0; i < nombreIterations; ++i) {
            std::cout << "Itération " << i + 1 << " :\n";

            // Sauvegarde de l'état actuel de la grille dans un fichier
            std::string nomFichier = "Etat_Iteration_" + std::to_string(i + 1) + ".txt";
            try {
                fichierTexte.sauvegarder(nomFichier, *simulation.getGrille());  // Utilisation de l'instance
            } catch (const std::exception& e) {
                std::cerr << "Erreur lors de la sauvegarde de l'état de l'itération : " << e.what() << std::endl;
            }

            // Affichage de l'état de la grille dans la console
            simulation.demarrer();

            std::cin.ignore();  // Attente de l'utilisateur
        }
    }

    // Sauvegarde de l'état final
    std::string fichierFinal = "GrilleFinale.txt";
    try {
        fichierTexte.sauvegarder(fichierFinal, *simulation.getGrille());  // Utilisation de l'instance
        std::cout << "État final sauvegardé dans '" << fichierFinal << "'.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la sauvegarde de l'état final : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
