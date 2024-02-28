Ce Projet sert à manipuler des images au format .ppm. 
Il propose un menu interactif offrant plusieurs fonctionnalités, laissant à l'utilisateur le choix des modifications à apporter en sélectionnant le numéro correspondant sur le menu.
Le programme continue à proposer des options de modification de l'image, affichant le menu jusqu'à ce que l'utilisateur choisisse l'option stop. Une fois les modifications terminées, le programme demande à l'utilisateur de spécifier le nom du fichier .ppm dans lequel l'image modifiée sera enregistrée.

Des notions de base qui peuvent faciliter la manipulation de ce projet:
*Une image est un ensemble de pixels.
*Dans une image, chaque pixel est composé de degrés de Rouge, Vert et Bleu, formant ainsi une couleur. 
*La couleur gris se forme lorsque le degré Rouge = degré Vert = degré Bleu
*La couleur noir se forme lorsque degré Rouge=Vert=Bleu= zéro
*La couleur blanche se forme lorsque degré Rouge=Vert=Bleu= 255
*Une couleur est plus clair lorsque la moyenne de ses composantes est plus proche de 255
**Une couleur est plus clair lorsque la moyenne de ses composantes est plus proche de 0

Les fonctionnalités disponibles sont les suivantes :
1.   Afficher l'image, pixel par pixel
2.  Garder les composantes Rouge et transformer les autres en 0
3 .  Vérifier si un pixel donné existe dans l'image
4 . transformer l'image en gris en faisant la moyenne de chaque pixel
5 . transformer l'image en noir et blanc selon un seuil donné: si le pixel est plus clair ou égal à la seuil => blanc, sinon noir
6 . afficher l'histogramme gris
7 . afficher l'histogramme couleurs
8 . Augmenter le contrast d'une image selon un facteur choisi (reel >1)
9 .Diminuer le contrast d'une image selon un facteur choisi(reel<1)
10 . Augmenter la luminoste d'une image selon un facteur choisi(reel>1)
11 . Diminuer la luminoste d'une image selon un facteur choisi (reel<1)
12 . Rogner l'image en bas en supprimant nb lignes souhaiteés(entier respectant les dimensions de l'image)
13 . Rogner l'image en haut en supprimant nb lignes souhaités(entier respectant les dimensions de l'image)
14 . Rogner l'image à droite en supprimant nb colonnes souhaités(entier respectant les dimensions de l'image)
15 . Rogner l'image à gauche en supprimant nb colonnes souhaités(entier respectant les dimensions de l'image)
16 . Rotation 90° de l'image vers la droite
17 .Rotation 90° de l'image vers la gauche
18 . Retournement de l'image selon l'axe horiental
19 . Retournement de l'image selon l'axe vertical
20 . Agrandir l'image en duppliquant chaque pixel facteur² fois(reel >1)

Pour arrêter le processus, saisissez -1 pour sélectionner l'option "stop".

PS: Il faut extraire le dossir 'images.zip' dans le dossier principales pour avoir accès aux images .ppm