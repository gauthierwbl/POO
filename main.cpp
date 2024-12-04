#include "Simulation.h"
#include "FichierTexte.h"
#include "Grille.h"
#include "Cellule.h"
#include "BibliothequeMotif.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
    // Dimensions de la grille
    int largeur = 10;
    int hauteur = 10;
    bool torique = true;  // Grille torique (si applicable)
    int nombreIterations = 5;

    // Crée une simulation avec la grille spécifiée
    Simulation simulation(largeur, hauteur, torique, nombreIterations);

    // Crée une bibliothèque de motifs
    BibliothèqueMotif bibliotheque;

    // Demander à l'utilisateur s'il veut ajouter un motif
    char choix;
    std::cout << "Voulez-vous ajouter des motifs à la bibliothèque (O/N) ? ";
    std::cin >> choix;

    if (choix == 'O' || choix == 'o') {
        // Ajoute les motifs prédéfinis à la bibliothèque
        bibliotheque.ajouterMotifDepuisClavier();
    }

    // Afficher la liste des motifs disponibles dans la bibliothèque
    std::cout << "Voici les motifs disponibles dans la bibliothèque :\n";
    bibliotheque.afficherListeMotifs();

    // Vérifier si le fichier GrilleInitiale.txt existe
    std::string cheminFichier = "GrilleInitiale.txt";
    std::ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        // Si le fichier n'existe pas, générer une grille aléatoire
        std::cout << "Le fichier " << cheminFichier << " n'existe pas. Génération d'une grille aléatoire.\n";
        try {
            // Générer une grille aléatoire et la sauvegarder dans GrilleInitiale.txt
            FichierTexte::genererGrilleAleatoire(cheminFichier, largeur, hauteur);
            std::cout << "Grille générée et sauvegardée dans " << cheminFichier << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la génération de la grille aléatoire : " << e.what() << std::endl;
            return 1;  // Arrêt en cas d'erreur
        }
    }

    // Charger l'état initial depuis le fichier texte
    try {
        // Charger l'état initial de la grille
        FichierTexte::charger(cheminFichier, *simulation.getGrille());
        std::cout << "État initial chargé depuis " << cheminFichier << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement de l'état initial : " << e.what() << std::endl;
        return 1;  // Arrêt en cas d'erreur
    }

    // Demander à l'utilisateur quel motif insérer dans la grille
    Motif* motifChoisi = nullptr;
    if (choix == 'O' || choix == 'o') {
        std::cout << "Choisissez un motif à insérer dans la grille parmi les suivants :\n";
        std::cout << "1 - Glider\n2 - Bloc\n3 - Oscillateur\n";
        int choixMotif;
        std::cin >> choixMotif;

        switch (choixMotif) {
            case 1:
                motifChoisi = bibliotheque.getMotifParNom("Glider");
                break;
            case 2:
                motifChoisi = bibliotheque.getMotifParNom("Bloc");
                break;
            case 3:
                motifChoisi = bibliotheque.getMotifParNom("Oscillateur");
                break;
            default:
                std::cout << "Choix invalide.\n";
                return 1;
        }

        if (motifChoisi != nullptr) {
            std::cout << "Motif choisi : " << motifChoisi->getNom() << std::endl;
            // Ajouter le motif à la grille sans vérification des dimensions
            simulation.getGrille()->ajouterMotifDansGrille(*motifChoisi);
        } else {
            std::cerr << "Motif non trouvé dans la bibliothèque.\n";
            return 1;
        }
    } else {
        std::cout << "Aucun motif ajouté. La grille va rester aléatoire.\n";
    }

    // Démarre la simulation
    std::cout << "Démarrage de la simulation...\n";
    simulation.demarrer();

    // Sauvegarder l'état final de la grille dans un fichier texte
    std::string fichierFinal = "GrilleFinale.txt";

    // Vérifier si le fichier existe déjà
    std::ifstream fichierFinalCheck(fichierFinal);
    if (fichierFinalCheck.is_open()) {
        char reponse;
        std::cout << "Le fichier " << fichierFinal << " existe déjà. Voulez-vous l'écraser (O/N) ? ";
        std::cin >> reponse;
        if (reponse != 'O' && reponse != 'o') {
            std::cout << "Sauvegarde annulée.\n";
            return 0;
        }
    }

    // Sauvegarder l'état final de la grille
    try {
        FichierTexte::sauvegarder(fichierFinal, *simulation.getGrille());
        std::cout << "Simulation terminée, état final sauvegardé dans " << fichierFinal << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la sauvegarde de l'état final : " << e.what() << std::endl;
        return 1;  // Arrêt en cas d'erreur
    }

    return 0;
}
