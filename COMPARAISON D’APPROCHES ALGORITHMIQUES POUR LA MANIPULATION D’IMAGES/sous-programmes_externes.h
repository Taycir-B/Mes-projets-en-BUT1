#ifndef SOUSPROGRAMMEEXTERNES_H_INCLUDED
#define SOUSPROGRAMMEEXTERNES_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
///fonctions externes
//---------------NBGris.pdf-----------------------------------
int tableauxMemeTailles(const vector<vector<int>> &tab1, const vector<vector<int>> &tab2, const vector<vector<int>> &tab3);
void afficheVect2D(const vector<vector<int>> & tab2D);//affiche un vecteur 2D d'entiers
void afficheVect2Dfloat(const vector<vector<float>> &tab2D);//affiche un vecteur 2D de flottant
void afficheVect3D(const vector<vector<vector<int>>> &tab3D);//affiche un vecteur 3D d'entiers
void afficheVect1D(const vector <int> & tab);//affiche un vecteur 1D d'entiers
void saisieComposantePixel(int &x);//saisie d'une composante de pixel: une valeur entre 0 et 255
void saisieRVB(int &r, int &v, int &b);//saisie tout le pixel RVB
void contrastAppliqueComposante(vector<vector<int>> &composante, int i, int j, float contrastCalcule);
void saisieFacteurUp(float &facteurUp);//saisir un facteur d'augmentation - supérieur à 1
void saisieFacteurDown(float &facteurDown);//saisir un facteur de diminution - inférieur à 1
//--------------MenuFichiers.pdf--------------------------------
void saisiNomImagePPM( string &nomImage);//saisir un nom de fichier image en format .ppm
void saisiNomEnregistrementPPM(string &nomImage);//saisir un nom de fichier image en format .ppm pour l'enregistrement
void loadPicture(const string &picture, vector<vector<int>> &red,
                                        vector<vector<int>> &green,
                                        vector <vector<int>> &blue);
//------------GeometrieTaille.pdf--------------------------------
//saisie de nb colonne à supprimer au rognement bas/haut de l'image
void saisieNbLignesRogner(int &nb, int largeur);//entier > 0 et < longueur de l'image
//saisie de nb colonne à supprimer au rognement gauche/droite de l'image
void saisieNbColonnesRogner(int &nb, int longueur);//entier > 0 et < largeur de l'image
void saisieFacteurAggrandir(int &facteurAggrandir);//saisie du facteur d'agrandissement de l'image: entier>1
///----------------fonctions externes (d'encapsulation) ----------------------------------
//MenuFichiers (question 2)
Image packCreerImage();//retourne une image creee à partir d'un fichier ppm donné
#endif
