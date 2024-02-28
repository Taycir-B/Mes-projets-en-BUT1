## Projet de Traitement d'Images en C++
Ce projet C++ vise à manipuler des images au format .ppm en offrant diverses fonctionnalités de traitement. L'utilisateur peut choisir ces fonctionnalités à partir d'un menu interactif.

## Notions de Base
- Une image est un ensemble de pixels.
- Chaque pixel dans une image est composé de degrés de Rouge, Vert et Bleu.
- La couleur gris se forme lorsque le degré Rouge = degré Vert = degré Bleu.
- La couleur noire se forme lorsque degré Rouge = Vert = Bleu = 0.
- La couleur blanche se forme lorsque degré Rouge = Vert = Bleu = 255.
- Une couleur est plus claire lorsque la moyenne de ses composantes est proche de 255.
- Une couleur est plus sombre lorsque la moyenne de ses composantes est proche de 0.

## Guide
Le programme principal propose un menu interactif offrant plusieurs fonctionnalités, laissant à l'utilisateur le choix des modifications à apporter en sélectionnant le numéro correspondant sur le menu.
Le programme continue à proposer des options de modification de l'image, affichant le menu jusqu'à ce que l'utilisateur choisisse l'option stop. Une fois les modifications terminées, le programme demande à l'utilisateur de spécifier le nom du fichier .ppm dans lequel l'image modifiée sera enregistrée.

## Fonctionnalités Principales
1. Afficher l'image, pixel par pixel.
2. Garder les composantes Rouge et transformer les autres en 0.
3. Vérifier si un pixel donné existe dans l'image.
4. Transformer l'image en niveau de gris en faisant la moyenne de chaque pixel.
5. Transformer l'image en noir et blanc selon un seuil donné.
6. Afficher l'histogramme en niveaux de gris.
7. Afficher l'histogramme des couleurs.
8. Augmenter le contraste d'une image selon un facteur choisi (réel > 1).
9. Diminuer le contraste d'une image selon un facteur choisi (réel < 1).
10. Augmenter la luminosité d'une image selon un facteur choisi (réel > 1).
11. Diminuer la luminosité d'une image selon un facteur choisi (réel < 1).
12. Rogner l'image en bas en supprimant un nombre de lignes souhaité (entier respectant les dimensions de l'image).
13. Rogner l'image en haut en supprimant un nombre de lignes souhaité (entier respectant les dimensions de l'image).
14. Rogner l'image à droite en supprimant un nombre de colonnes souhaité (entier respectant les dimensions de l'image).
15. Rogner l'image à gauche en supprimant un nombre de colonnes souhaité (entier respectant les dimensions de l'image).
16. Rotation de 90° de l'image vers la droite.
17. Rotation de 90° de l'image vers la gauche.
18. Retournement de l'image selon l'axe horizontal.
19. Retournement de l'image selon l'axe vertical.
20. Agrandir l'image en dupliquant chaque pixel un certain nombre de fois (réel > 1).

## Utilisation
1. Compilez le projet en utilisant votre compilateur C++ préféré.
2. Exécutez l'application résultante.
3. Suivez les instructions du menu interactif pour appliquer les modifications souhaitées à l'image.

## Instructions d'Installation
- Extrayez le dossier 'images.zip' dans le dossier principal pour avoir accès aux images .ppm.

## Auteur
Taycir BEN OUIRANE

## Licence
Ce projet est sous licence Apache-2.0 license.
