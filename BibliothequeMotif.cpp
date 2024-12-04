#include "BibliothequeMotif.h"
#include <iostream>

void BibliothèqueMotif::ajouterMotifDepuisClavier() {
    // Propose trois motifs prédéfinis
    std::cout << "Choisissez un motif à ajouter (1, 2 ou 3) :\n";
    std::cout << "1 - Glider\n";
    std::cout << "2 - Bloc\n";
    std::cout << "3 - Oscillateur\n";

    int choix;
    std::cin >> choix;  // Lecture du choix de l'utilisateur

    // Selon le choix de l'utilisateur, on ajoute un motif prédéfini
    if (choix == 1) {
        motifs.push_back(Motif::createGlider());
    } else if (choix == 2) {
        motifs.push_back(Motif::createBloc());
    } else if (choix == 3) {
        motifs.push_back(Motif::createOscillateur());
    } else {
        std::cout << "Choix invalide.\n";
    }
}

Motif* BibliothèqueMotif::getMotifParNom(const std::string& nom) {
    for (auto& motif : motifs) {
        if (motif.getNom() == nom) {
            return &motif;  // Retourne l'adresse du motif trouvé
        }
    }
    return nullptr;  // Si aucun motif n'est trouvé
}

void BibliothèqueMotif::afficherListeMotifs() const {
    std::cout << "Liste des motifs dans la bibliothèque :\n";
    for (const auto& motif : motifs) {
        std::cout << "Motif : " << motif.getNom() << ", Taille : " << motif.getLargeur() << "x" << motif.getHauteur() << std::endl;
    }
}
