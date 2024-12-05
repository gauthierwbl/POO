#ifndef BIBLIOTHEQUEMOTIF_H
#define BIBLIOTHEQUEMOTIF_H

#include "Motif.h"  // Assurez-vous que Motif.h existe et contient la classe Motif
#include <vector>
#include <string>

class BibliothequeMotif {
private:
    std::vector<Motif> motifs;  // Liste des motifs

public:
    void ajouterMotifDepuisClavier(); // Méthode pour ajouter un motif
    Motif* getMotifParNom(const std::string& nom); // Trouver un motif par son nom
    void afficherListeMotifs() const;  // Afficher la liste des motifs disponibles
};

#endif // BIBLIOTHEQUEMOTIF_H
