#include <iostream>
#include <exception>
#include "image.h"
#include "menu.h"
#include "filtre.h"
#include "sous-programmes_externes.h"

using namespace std;
int mainTest(){
    vector<vector<int>> rouge = {{0,0,0,0},{0,0,255,255},{0,255,255,255},{255,255,255,255}};
    vector<vector<int>> vert = {{0,0,255,255},{0,255,255,255},{255,255,255,0},{255,255,0,0}};
    vector<vector<int>> bleu = {{255,255,0,0},{255,0,0,0},{0,0,0,0},{0,0,0,0}};


    vector<vector<int>> vecteurvide = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    Image imageTest(rouge,vert,bleu);
    Image imageCopie = imageTest;


    cout << "-----------------------------Jeu de Test methode detection----------------------------"<< endl;
    cout << "---------Cas General------------" << endl;
    imageTest.afficheImage();
    bool detect;
    detect = imageTest.detection(255, 0, 0);
    if (detect)
        cout << "Test reussi!!" << endl;
    else
        cout << "Erreur : affichage : " << detect << ", Attendu : True" << endl;
    cout << "---------Cas ou le pixel n'existe pas------------" << endl;
    detect = imageTest.detection(42, 255, 0);
    if (!detect)
    cout << "Test reussi!!" << endl;
    else
    cout << "Erreur : affichage : " << detect << ", Attendu : False" << endl<<endl;

    cout << "-----------------------------Jeu de Test methode composanteRouge----------------------------"<< endl;
    cout << "---------Cas General------------" << endl;
    imageTest.afficheImage();
    imageTest = imageTest.composanteRouge();
    if (imageTest.getBlue() == vecteurvide && imageTest.getGreen() == vecteurvide && imageTest.getRed() == imageCopie.getRed())
        cout << "Test reussi!!" << endl;
    else{
        cout << "Erreur : affichage : "<<endl;
        imageTest.afficheImage();
        cout<< "Attendu : "<<endl;
        cout<<"Rouge : "<<endl;
        afficheVect2D(imageCopie.getRed());
        cout<<endl;
        cout<<"Vert : "<<endl;
        afficheVect2D(vecteurvide);
        cout<<endl;
        cout<<"Bleu : "<<endl;
        afficheVect2D(vecteurvide);}

    imageTest = imageCopie;
    cout << "-----------------------------Jeu de Test methode niveauxGris----------------------------"<< endl;
    cout << "---------Cas General------------" << endl;
    vector<vector<int>> vecteurgris = {{85,85,85,85},{85,85,170,170},{85,170,170,85},{170,170,85,85}};
    imageTest.afficheImage();
    imageTest = imageTest.niveauxGris();
    if (imageTest.getRed() == vecteurgris && imageTest.getGreen() == vecteurgris && imageTest.getBlue() == vecteurgris)
        cout << "Test reussi!!" << endl;
    else{
        cout << "Erreur : affichage : "<<endl;
        imageTest.afficheImage();
        cout<< "Attendu : "<<endl;
        cout<<"Rouge : {{85,85,85,85},{85,85,170,170},{85,170,170,85},{170,170,85,85}}"<<endl<<endl;
        cout<<"Vert : {{85,85,85,85},{85,85,170,170},{85,170,170,85},{170,170,85,85}}"<<endl<<endl;
        cout<<"Bleu : {{85,85,85,85},{85,85,170,170},{85,170,170,85},{170,170,85,85}}"<<endl<<endl;}


    imageTest = imageCopie;
    cout << "-----------------------------Jeu de Test methode noirEtBlanc----------------------------"<< endl;
    cout << "---------Cas General------------" << endl;
    vector<vector<int>> noiretBlanc = {{0,0,0,0},{0,0,255,255},{0,255,255,0},{255,255,0,0}};
    imageTest.afficheImage();
    imageTest = imageTest.noirETBlanc(100);
    if (imageTest.getRed() == noiretBlanc && imageTest.getGreen() == noiretBlanc && imageTest.getBlue() == noiretBlanc)
        cout << "Test reussi!!" << endl;
    else{
        cout << "Erreur : affichage : "<<endl;
        imageTest.afficheImage();
        cout<< "Attendu : "<<endl;
        cout<<"Rouge : {{0,0,0,0},{0,0,255,255},{0,255,255,0},{255,255,0,0}}"<<endl<<endl;
        cout<<"Vert : {{0,0,0,0},{0,0,255,255},{0,255,255,0},{255,255,0,0}}"<<endl<<endl;
        cout<<"Bleu : {{0,0,0,0},{0,0,255,255},{0,255,255,0},{255,255,0,0}}"<<endl<<endl;}

    imageTest = imageCopie;
    cout << "-----------------------------Jeu de Test methode histogrammeGris----------------------------"<< endl;
    cout << "---------Cas General------------" << endl;
    imageTest = imageTest.niveauxGris();
    imageTest.afficheImage();
    vector<int> histo = imageTest.histogrammeGris();
    if (histo[85] == 10 && histo[170] == 6)
        cout << "Test reussi!!" << endl;
    else{
        cout << "Erreur : affichage : "<<endl;
        imageTest.afficheImage();
        cout<< "Attendu : "<<endl;
        cout<<"un histogramme de 256 case (0-255) avec des zeros sauf à la case 85 (valeur = 10) et 170 (valeur = 6)"<<endl;}

    cout<<"-------------------------------------------------Test filtre-----------------------------------"<<endl;
    rouge = {{0,50,100,150},{50,100,150,200},{100,150,200,225},{150,200,225,255}};
    vector<vector<float>> matricefiltre = {{(float)1/16,(float)1/8,(float)1/16},{(float)1/8,(float)1/4,(float)1/8},{(float)1/16,(float)1/8,(float)1/16}};
    cout<<"Affichage du filtre: "<<endl;
    afficheVect2Dfloat(matricefiltre);
    Image imagefiltre(rouge,rouge,rouge);
    Image imageResult(rouge,vert,bleu);
    cout<<"Affichage imagefiltre"<<endl;
    imagefiltre.afficheImage();
    Filtre filtretest(matricefiltre,1);
    imageResult =filtretest.application(imagefiltre);
    cout<<"Affichage image apres filtre: "<<endl;
    imageResult.afficheImage();
    //---question 2 FILTRE
    vector<vector<float>> matriceflouG3 = {{(float)1/16,(float)1/8,(float)1/16},{(float)1/8,(float)1/4,(float)1/8},{(float)1/16,(float)1/8,(float)1/16}};
    Filtre(matriceflouG3, 1);//rayon = 1!

}
