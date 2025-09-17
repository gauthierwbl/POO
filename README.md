# 🧬 POO-main – Jeu de la Vie (C++ & SFML)

## 📌 Description
Ce projet est une implémentation en **C++ orienté objet** du célèbre **Jeu de la Vie de Conway**.  
L’objectif est de simuler l’évolution d’une grille composée de cellules **vivantes** ou **mortes**, avec possibilité d’interactions via une interface graphique.

Le projet illustre les concepts de **programmation orientée objet (POO)** : héritage, encapsulation, polymorphisme, gestion de fichiers et interface graphique.

---

## 🚀 Fonctionnalités principales
- 🔲 Représentation d’une grille de cellules vivantes et mortes  
- ▶️ Simulation de l’évolution des générations selon les règles de Conway  
- 📂 Lecture et sauvegarde de grilles depuis/vers des fichiers texte  
- 🖥️ Interface graphique (basée sur **SFML**) pour visualiser la simulation  
- ⚙️ Utilisation d’un **Makefile** pour compiler facilement le projet  

---

## 🛠️ Technologies utilisées
- **C++ (POO)**  
- **SFML** pour l’affichage graphique  
- **Makefile** pour la compilation et l’exécution  

---

## 📂 Structure du projet
```bash
POO-main/
│── main.cpp                  # Point d’entrée
│── Makefile                  # Script de compilation
│
├── Cellule.cpp / .h          # Classe de base pour une cellule
├── CelluleVivante.cpp / .h   # Cellule vivante
├── CelluleMorte.cpp / .h     # Cellule morte
│
├── Grille.cpp / .h           # Gestion de la grille
├── Simulation.cpp / .h       # Logique de simulation
├── FichierTexte.cpp / .h     # Lecture/écriture de fichiers
├── InterfaceGraphique.cpp/.h # Affichage graphique
│
├── GrilleInitiale.txt        # Exemple de grille de départ
└── GrilleFinale.txt          # Exemple de grille sauvegardée

