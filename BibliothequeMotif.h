#ifndef BIBLIOTHEQUEMOTIF_H
#define BIBLIOTHEQUEMOTIF_H

#include "Motif.h"  // Assurez-vous que Motif.h existe et contient la classe Motif
#include <vector>   // Inclusion de la bibliothèque vector pour utiliser des vecteurs
#include <string>   // Inclusion de la bibliothèque string pour utiliser des chaînes de caractères

// Déclaration de la classe BibliothequeMotif
class BibliothequeMotif {
private:
    std::vector<Motif> motifs;  // Liste des motifs stockés dans un vecteur

public:
    // Méthode pour ajouter un motif depuis l'entrée clavier
    void ajouterMotifDepuisClavier(); 

    // Méthode pour trouver un motif par son nom
    Motif* getMotifParNom(const std::string& nom); 

    // Méthode pour afficher la liste des motifs disponibles
    void afficherListeMotifs() const;  
};

#endif // BIBLIOTHEQUEMOTIF_H
