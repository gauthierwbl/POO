#ifndef FICHIER_TEXTE_H
#define FICHIER_TEXTE_H

#include <string>
#include "CelluleVivante.h"
#include "CelluleMorte.h"
#include "Grille.h"
#include "Cellule.h"

class FichierTexte {
public:
    // Charge une grille depuis un fichier texte
    static void charger(const std::string& chemin, Grille& grille);

    // Sauvegarde une grille dans un fichier texte
    static void sauvegarder(const std::string& chemin, const Grille& grille);

    // Crée un fichier avec une grille aléatoire
    static void genererGrilleAleatoire(const std::string& chemin, int largeur, int hauteur);

private:
    // Méthodes utilitaires pour manipuler des fichiers texte brut
    static std::string lireFichierTexte(const std::string& chemin);
    static void ecrireFichierTexte(const std::string& chemin, const std::string& contenu);
};

#endif // FICHIER_TEXTE_H
