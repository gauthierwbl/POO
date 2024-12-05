#include "Simulation.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructeur de la classe Simulation
Simulation::Simulation(int largeur, int hauteur, bool torique, int nombreIterations)
    : nombreIterations(nombreIterations), grille(new Grille(largeur, hauteur, torique)) {
    // Initialise la simulation avec une grille de dimensions spécifiées
}

// Destructeur
Simulation::~Simulation() {
    delete grille;  // Libère la mémoire allouée pour la grille
}

// Setter pour la grille
void Simulation::setGrille(Grille* nouvelleGrille) {
    if (grille != nullptr) {
        delete grille;  // Libère la mémoire de l'ancienne grille
    }
    grille = nouvelleGrille; // Assigne la nouvelle grille
}

// Démarre la simulation
void Simulation::demarrer() {
    grille->afficherConsole(); // Affiche l'état courant de la grille
    for (int i = 0; i < nombreIterations; ++i) {
        grille->calculerEtatsSuivants(); // Calcule les états suivants
        grille->mettreAJour(); // Met à jour l'affichage de la grille
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause pour visualiser les changements
    }
}

// Charge un état initial depuis un fichier
void Simulation::chargerEtatInitial(const std::string& cheminFichier) {
    try {
        FichierTexte::charger(cheminFichier, *grille); // Tente de charger l'état initial
    } catch (const std::runtime_error& e) {
        std::cerr << "Erreur lors du chargement de l'état initial : " << e.what() << std::endl;
        // Si le fichier n'existe pas, crée un état initial par défaut
        std::cout << "Création d'un état initial par défaut..." << std::endl;
        FichierTexte::sauvegarder("GrilleStart.txt", *grille); // Sauvegarde l'état par défaut
    }
}

// Sauvegarde l'état courant dans un fichier
void Simulation::sauvegarderEtatCourant(const std::string& cheminFichier) {
    FichierTexte::sauvegarder(cheminFichier, *grille); // Sauvegarde l'état courant de la grille
}

// Ajoute un motif à la grille
void Simulation::ajouterMotifDansGrille(const Motif& motif) {
    // Utilisation de la méthode d'ajout du motif dans la grille
    grille->ajouterMotifDansGrille(motif); // Ajoute le motif à la grille
}
