#include "InterfaceGraphique.h"
#include "Grille.h"

InterfaceGraphique::InterfaceGraphique(int width, int height, int cellSize, Simulation* sim)
    : cellSize(cellSize), simulation(sim),
      window(sf::VideoMode(width * cellSize, height * cellSize), "Jeu de la Vie") {
    window.setFramerateLimit(60);
}

void InterfaceGraphique::afficherGrille() {
    window.clear(sf::Color::Black);
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));

    Grille* grille = simulation->getGrille(); // Access Grille via Simulation
    for (int x = 0; x < grille->getLargeur(); ++x) {
        for (int y = 0; y < grille->getHauteur(); ++y) {
            cell.setPosition(x * cellSize, y * cellSize);
            cell.setFillColor(grille->getCellule(x, y)->getEtatActuel() ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }
    }
    window.display();
}

void InterfaceGraphique::mettreAJourAffichage() {
    afficherGrille();
}

void InterfaceGraphique::gererInteractionsUtilisateur() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        // Additional user interactions can be added here
    }
}

void InterfaceGraphique::demarrer() {
    window.clear(sf::Color::Black);
    window.display();
}

void InterfaceGraphique::arreter() {
    window.close();
}

bool InterfaceGraphique::estOuverte() const {
    return window.isOpen();
}