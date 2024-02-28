#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
///constantes
const int ROUGE=0,BLEU=1,VERT=2;//pour redimensionner les composantes (utile pour le rognement)

///classe Image
class Image
{
    vector<vector<int>> _rouge;
    vector<vector<int>> _vert;
    vector<vector<int>> _bleu;
    int _longueur;
    int _largeur;
public:
    ///-----constructeurs
    //--NBGris  question1
    Image(vector<vector<int>> & rouge,vector<vector<int>> & vert,vector<vector<int>> & bleu);
    //construit une image à partir des 3 composantes rouge vert bleu

    //***MenuFchiers ----question2
    Image(const string &nomImage);
    //construit une image à partir d'un fichier ppm

    ///geters()
    int getLongueur()const{return _longueur;}
    int getLargeur()const{return _largeur;}
    ///-----methodes de consultation
    //*****NBGris****//
    void afficheImage() const;
    vector<int> getPixel(int x, int y)const;
    //retourne le pixel(degres rouge, vert, bleu)de position image[x][y]
    //sous forme d'un vecteur

    vector<vector<int>> getRed()const;
    vector<vector<int>> getGreen()const;
    vector<vector<int>> getBlue()const;

    //---question3 NBGris
    Image composanteRouge()const;//creer une nouvelle image à partir de la cible
    //en gardant les memes composantes rouge et
    //les aures composantes à zero

    //---question4 NBGris
    bool detection(int R, int V, int B)const;
    //retourne vrai si le pixel (R,V,B) est present dans l'image
    //sinon faux

    //---question5 NBGris
    Image niveauxGris() const;
    //créer une image à partir de l’image cible ou' chaque pixel est gris
    //le niveau du gris de chaque pixel est la moyenne des trois composantes

    //---question7 NBGris
    Image noirETBlanc(int seuil)const;//creer une image noir et blanc à partir de l’image cible
    //si le niveau de gris est plus clair(superieur) qu’un seuil le pixel sera blanc
    //si il est plus sombre(inferieur) que le seuil le pixel sera noir

    //---question8 (2etoiles) NBGris
    vector<int> histogrammeGris()const;//retourne un vecteur d’entiers
    //représentant l’histogramme de l’image en niveau de gris
    //la case d’indice i représente le nombre de pixels dont le niveau de gris est i

    //---question10 (2etoiles) NBGris
    Image luminosityUp(float facteur) const;//cree une image avec à partir de l’image cible
    //dont sa luminosité est augmentée selon le facteur(superieur à 1) donné
    Image luminosityDown(float facteur) const;//creer une image avec à partir de l’image cible
    //dont sa luminosité est diminuée selon le facteur(inferieur à 1) donné

    //---question11 (2etoiles) NBGris
    Image contrastUp(float facteur)const;//cree une image à partir de l’image cible
    //dont le contraste a été augmenté en fonction du facteur donné
    Image contrastDown(float facteur)const;//cree une image à partir de l’image cible
    //dont le contraste a été diminué en fonction du facteur donné

    //---question9 (3etoiles) NBGris
    vector<vector<vector<int>>> histogrammeCouleur()const;

    //***********MenuFichiers********************
    //---question 3 MenuFichiers
    void ecrireFichierPPM( ofstream& o)const;


    //****GeometrieTaile***************
    //---question1
    //créer une nouvelle image à partir de l’image cible qui
    void redimensionnerComposante(vector<vector<int>> &composante, int nouvelleTaille);//methode intermediaire pour le rognement
    Image rognerD(int nb) const;//supprime nb des colonnes de pixel de l’image à droite
    Image rognerG(int nb)const;//supprime nb des colonnes de pixel de l’image à gauche
    Image rognerB(int nb) const;//supprime nb des lignes de pixel de l’image en bas
    Image rognerH(int nb) const;//supprime nb des lignes de pixel de l’image en haut

    //---quetion 2+ 3(2etoiles)
    //creer une nouvelle image à partir de la cible
    Image rotationD()const;//qui effectue une rotation de l’image de 90° vers le sens horaire
    Image rotationG()const;//qui effectue une rotation de l’image de 90° vers le sens trigonometrique
    //--quetion 4
    //creer une nouvelle image à partir de la cible
    Image retournementH()const;//qui effectue la symetrie de l’image selon un axe horizental
    Image retournementV()const;//qui effectue la symetrie de l’image selon un axe vertical
    //--question5 (2etoiles)
    //creer une nouvelle image à partir de la cible
    //en agrandissant l'image selon un facteur donné en dupliquant les pixels
    Image agrandissement(int facteurAgrandissement)const;//Un pixel de l’image d’origine devient un carré de pixels.

    ///méthodes d'encapsulation
    //Toutes les fonctionnalité/ modifications sont proposées au menu
    //les methodes d'encapsulation facilitent la gestion

    //****NBGris getPixel
    void saisieIndicesImage(int &ligne, int &clonne);
    void packGetPixel();
    //saisie de la position du pixel à  extraire
    //retourne un vecteur à 1 dimension
    //ce vecteur contient les composantes RVB à la position donnée

    //*****NBGris detection
    void packDetection();
    //saisie RVB à cherher
    //recherche du RVB
    //précise si ce RVB donné existe dans l'image

    //*****NBGris noirETBlanc
    Image packNoirETBlanc();
    //saisie de la seuil de transformation
    //retourne une image noir et blanc selon la seuil donné

    //****NBGris luminosityUp
    Image packLuminosityUP();
    //saisie du facteur d'augmentation de la luminosité
    //retourne une image apres l'augmentation de sa luminosité

    //***NBGris luminosityDown
    Image packLuminosityDown();
    //saisie du facteur de diminuton de la luminosité
    //retourne une image apres dimunition de sa luminosité

    //****NBGris contrastUp
    Image packContrastUp();
    //saisie du facteur d'augmentation du contraste
    //retourne une image apres l'augmentation de son contraste

    //****NBGris contrastDown
    Image packContrastDown();
    //saisie du facteur du diminuton de contraste
    //retourne une image apres la diminution de son contraste

    //***MenuFichiers (question3) ecrireFichierPPM
    void packCreerFichier();
    //saisie du nom fichier image à créer
    //cree un fichier ppm correspondant à l'image cible


    //*******************GeometrieTaille****************
    Image packRognerB()const;
    //saisie du nombre de lignes à supprimer
    //retourner une imag rognée en bas

    Image packRognerH()const;
    //saisie du nombre de lignes à supprimer
    //retourner une imag rognée en haut

    Image packRognerG()const;
    //saisie du nombre de colonnes à supprimer
    //retourner une imag rognée à gauche

    Image packRognerD()const;
    //saisie du nombre de colonnes à supprimer
    //retourner une imag rognée à droite

    Image packAggrandissement()const;


};



#endif // IMAGE_H_INCLUDED

