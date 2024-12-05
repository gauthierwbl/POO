#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "FichierTexte.h"
#include "Grille.h"
#include "BibliothequeMotif.h"
#include "Cellule.h"

int main() {
    // Initialisation des paramètres
    int largeur = 10, hauteur = 10, nombreIterations = 30;
    bool torique = true;  // Grille torique

    // Création des objets principaux
    Simulation simulation(largeur, hauteur, torique, nombreIterations);
    BibliothèqueMotif bibliotheque;

    // Ajout des motifs par l'utilisateur
    char choix;
    std::cout << "Voulez-vous ajouter des motifs à la bibliothèque (O/N) ? ";
    std::cin >> choix;

    if (choix == 'O' || choix == 'o') {
        bibliotheque.ajouterMotifDepuisClavier();
    }

    std::cout << "Voici les motifs disponibles dans la bibliothèque :\n";
    bibliotheque.afficherListeMotifs();

    // Gestion du fichier d'état initial
    std::string cheminFichier = "GrilleInitiale.txt";
    std::ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cout << "Le fichier " << cheminFichier << " n'existe pas. Génération d'une grille aléatoire.\n";
        try {
            FichierTexte::genererGrilleAleatoire(cheminFichier, largeur, hauteur);
            std::cout << "Grille générée et sauvegardée dans " << cheminFichier << ".\n";
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la génération de la grille : " << e.what() << std::endl;
            return 1;
        }
    }

    try {
        FichierTexte::charger(cheminFichier, *simulation.getGrille());
        std::cout << "État initial chargé depuis " << cheminFichier << ".\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement de la grille : " << e.what() << std::endl;
        return 1;
    }

    // Choix du motif à ajouter
    Motif* motifChoisi = nullptr;
    if (choix == 'O' || choix == 'o') {
        int choixMotif = 0;
        while (choixMotif < 1 || choixMotif > 3) {
            std::cout << "Choisissez un motif à insérer dans la grille :\n";
            std::cout << "1 - Glider\n2 - Bloc\n3 - Oscillateur\n";
            std::cin >> choixMotif;
            if (choixMotif < 1 || choixMotif > 3) {
                std::cout << "Choix invalide. Veuillez entrer un chiffre entre 1 et 3.\n";
            }
        }

        switch (choixMotif) {
            case 1: motifChoisi = bibliotheque.getMotifParNom("Glider"); break;
            case 2: motifChoisi = bibliotheque.getMotifParNom("Bloc"); break;
            case 3: motifChoisi = bibliotheque.getMotifParNom("Oscillateur"); break;
        }

        if (motifChoisi) {
            simulation.getGrille()->ajouterMotifDansGrille(*motifChoisi);
            std::cout << "Motif ajouté à la grille.\n";
        } else {
            std::cerr << "Motif non trouvé.\n";
            return 1;
        }
    }

    // Choix du mode d'affichage
    char choixInterface;
    std::cout << "Voulez-vous utiliser l'interface graphique (G) ou la console (C) ? ";
    std::cin >> choixInterface;

    if (choixInterface == 'G' || choixInterface == 'g') {
        // Interface graphique avec SFML
        sf::RenderWindow window(sf::VideoMode(largeur * 20, hauteur * 20), "Jeu de la Vie");
        sf::RectangleShape cellule(sf::Vector2f(18, 18));

        int iterationActuelle = 0;
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
                    cellule.setFillColor(simulation.getGrille()->getCellule(x, y)->getEtatActuel() ? sf::Color::Black : sf::Color::White);
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
                FichierTexte::sauvegarder(nomFichier, *simulation.getGrille());
            } catch (const std::exception& e) {
                std::cerr << "Erreur lors de la sauvegarde de l'état de l'itération : " << e.what() << std::endl;
            }

            // Affichage de l'état de la grille dans la console
            simulation.demarrer();
            simulation.getGrille()->afficherConsole();
            std::cin.ignore();  // Attente de l'utilisateur
        }
    }

    // Sauvegarde de l'état final
    std::string fichierFinal = "GrilleFinale.txt";
    try {
        FichierTexte::sauvegarder(fichierFinal, *simulation.getGrille());
        std::cout << "État final sauvegardé dans '" << fichierFinal << "'.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la sauvegarde de l'état final : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
