# Jeu de Démineur Dynamique

Dans ce projet, j'ai développé un jeu de démineur dynamique en manipulant l'ajout et la suppression de contrôles depuis le code afin de rendre l'application interactive, et en utilisant des Layouts pour gérer le positionnement automatique des éléments.

## Objectifs

L'application permet de manipuler certains paramètres avant de lancer une nouvelle partie. En particulier, l'utilisateur peut choisir la taille de la grille (seules des grilles carrées sont utilisées pour simplifier) et le nombre de bombes.

Les principaux défis de ce projet incluent :
- **La création dynamique de contrôles** : Au début de chaque partie, une nouvelle grille de contrôles est créée dynamiquement depuis le code. Chaque contrôle dynamique est associé à une procédure événementielle qui fait appel aux algorithmes du jeu.
- **Les algorithmes du jeu** : En particulier, l'algorithme récursif qui parcourt les voisins d’une cellule cliquée. Cet algorithme vérifie les cellules voisines et continue à explorer jusqu'à ce que toutes les cellules non-bombées soient révélées.

## Développement

### Fonctionnalités du Jeu

1. **Grille Dynamique** : Au démarrage de l'application, une grille dynamique de contrôles est créée avec un placement aléatoire des bombes.
2. **Algorithmes de Jeu** : Implémentation des principaux algorithmes, y compris l'algorithme récursif pour révéler les cellules voisines.
3. **Menu de Configuration** : Un menu permet de configurer la taille de la grille et le nombre de bombes, et de relancer une nouvelle partie.

## Règles du Jeu

Le but du jeu de démineur est de révéler toutes les cellules d'une grille qui ne contiennent pas de bombes. Le joueur joue sur une grille dont les cellules sont toutes masquées au démarrage. Certaines cellules contiennent des bombes. Voici comment jouer :

1. **Révéler une Cellule :**
   - Le joueur clique sur une cellule pour révéler son contenu.
   - Si la cellule cliquée contient une bombe, la partie est immédiatement perdue.
   - Si la cellule cliquée ne contient pas de bombe, l'information révélée dépend du voisinage immédiat de la cellule.

2. **Cellule sans Bombe :**
   - Si la cellule cliquée ne contient pas de bombe et qu'au moins une bombe se trouve dans les cellules voisines immédiates (une case autour dans toutes les directions, y compris les diagonales), alors la cellule révèle le nombre de bombes dans son voisinage immédiat.
   - Si la cellule cliquée ne contient pas de bombe et qu'il n'y a aucune bombe dans les cellules voisines immédiates, alors la cellule révèle une case vide. Le jeu continue en révélant automatiquement les cellules voisines vides jusqu'à ce qu'une cellule avec des bombes voisines soit rencontrée.

3. **Indications Numériques :**
   - Les cellules révèlent un numéro indiquant le nombre de bombes présentes dans les cases voisines immédiates.

4. **Victoire :**
   - Le joueur gagne la partie en révélant toutes les cellules qui ne contiennent pas de bombes.

5. **Déduction :**
   - Le joueur utilise les nombres révélés pour déduire où sont probablement les bombes. En déduisant correctement, le joueur peut éviter les bombes et continuer à révéler des cellules sûres.

### Technologies Utilisées

- **Langage :** C#
- **Framework :** WPF (Windows Presentation Foundation)
- **Outils de Gestion de Projet :** travo et GIT
