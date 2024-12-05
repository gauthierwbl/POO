#ifndef INTERFACE_GRAPHIQUE_H
#define INTERFACE_GRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Simulation.h"

class InterfaceGraphique {
private:
    sf::RenderWindow window;
    const int cellSize;
    Simulation* simulation; // Pointer to the Simulation object

public:
    InterfaceGraphique(int width, int height, int cellSize, Simulation* sim);

    void afficherGrille();
    void mettreAJourAffichage();
    void gererInteractionsUtilisateur();
    void demarrer();
    void arreter();

    bool estOuverte() const;
};

#endif // INTERFACE_GRAPHIQUE_H