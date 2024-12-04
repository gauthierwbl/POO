#include "BibliothequeMotif.h"
#include <iostream>

void BibliothèqueMotif::ajouterMotifDepuisClavier() {
    // Ajoute les motifs prédéfinis sans demander à l'utilisateur
    motifs.push_back(Motif::createGlider());
    motifs.push_back(Motif::createBloc());
    motifs.push_back(Motif::createOscillateur());
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
