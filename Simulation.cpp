#include "Simulation.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructeur
Simulation::Simulation(int largeur, int hauteur, bool torique, int nombreIterations)
    : nombreIterations(nombreIterations), grille(new Grille(largeur, hauteur, torique)) {}

// Destructeur
Simulation::~Simulation() {
    delete grille;  // Libère la mémoire allouée pour la grille
}

// Setter pour la grille
void Simulation::setGrille(Grille* nouvelleGrille) {
    if (grille != nullptr) {
        delete grille;  // Libère la mémoire de l'ancienne grille
    }
    grille = nouvelleGrille;
}

// Démarre la simulation
void Simulation::demarrer() {
    grille->afficherConsole(); // Optionally display state
    grille->calculerEtatsSuivants();
    grille->mettreAJour();
}

// Charge un état initial depuis un fichier
void Simulation::chargerEtatInitial(const std::string& cheminFichier) {
    try {
        FichierTexte::charger(cheminFichier, *grille);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erreur lors du chargement de l'état initial : " << e.what() << std::endl;
        // Si le fichier n'existe pas, crée un état initial par défaut
        std::cout << "Création d'un état initial par défaut..." << std::endl;
        FichierTexte::sauvegarder("GrilleStart.txt", *grille);
    }
}

// Sauvegarde l'état courant dans un fichier
void Simulation::sauvegarderEtatCourant(const std::string& cheminFichier) {
    FichierTexte::sauvegarder(cheminFichier, *grille);
}

// Ajoute un motif à la grille
void Simulation::ajouterMotifDansGrille(const Motif& motif) {
    // Utilisation de la méthode d'ajout du motif dans la grille
    grille->ajouterMotifDansGrille(motif);
}
