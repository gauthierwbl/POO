#include "BibliothequeMotif.h"  // Inclusion de la classe BibliothequeMotif
#include <iostream>            // Inclusion de la bibliothèque iostream pour les entrées/sorties standard

// Méthode pour ajouter des motifs prédéfinis à la bibliothèque
void BibliothequeMotif::ajouterMotifDepuisClavier() {
    // Ajoute les motifs prédéfinis sans demander à l'utilisateur
    motifs.push_back(Motif::createGlider());     // Ajout d'un motif de type Glider
    motifs.push_back(Motif::createBloc());        // Ajout d'un motif de type Bloc
    motifs.push_back(Motif::createOscillateur()); // Ajout d'un motif de type Oscillateur
}

// Méthode pour obtenir un motif par son nom
Motif* BibliothequeMotif::getMotifParNom(const std::string& nom) {
    // Parcourt tous les motifs dans la bibliothèque
    for (auto& motif : motifs) {
        // Vérifie si le nom du motif correspond au nom recherché
        if (motif.getNom() == nom) {
            return &motif;  // Retourne l'adresse du motif trouvé
        }
    }
    return nullptr;  // Retourne nullptr si aucun motif n'est trouvé
}

// Méthode pour afficher la liste des motifs disponibles dans la bibliothèque
void BibliothequeMotif::afficherListeMotifs() const {
    std::cout << "Liste des motifs dans la bibliothèque :\n"; // Affiche un en-tête
    // Parcourt tous les motifs et affiche leurs détails
    for (const auto& motif : motifs) {
        std::cout << "Motif : " << motif.getNom() << ", Taille : " 
                  << motif.getLargeur() << "x" << motif.getHauteur() << std::endl;
    }
}
