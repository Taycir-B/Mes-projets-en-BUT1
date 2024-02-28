#include <iostream>
#include "image.h"
#include "sous-programmes_externes.h"
#include "menu.h"
using namespace std;

void saisieChoix(int &choix)
//controle de saisie sur le choix de la commande
//On demande la saisie du choix tant que le choix précisé n'est pas sur le menu
{
    cout<<"Veuillez choisir une commande entre 1 et "<<MAXFONCTIONNALITES<<": ";
    cin>>choix;
    while((choix > MAXFONCTIONNALITES || choix <= 0) && choix != STOP)
    {
        cout<<"!! choix doit etre entre 1 et "<<MAXFONCTIONNALITES<<": ";
        cin>>choix;
    }
}

void menu(int &choix)
//afficher un menu
{
    cout<<endl;
    cout<<"Quelles operations/modifications souhaitez-vous effectuer? "<<endl;
    cout<<"1 : Afficher l'image "<<endl;
    cout<<"2 : Garder les composantes Rouge et transformer les autres en noir "<<endl;
    cout<<"3 : Verifier si un pixel donne existe dans l'image "<<endl;
    cout<<"4 : transformer l'image en gris en faisant la moyenne de chaque pixel"<<endl;
    cout<<"5 : transformer l'image en noir et blanc"<<endl;
    cout<<"6 : afficher l'histogramme gris"<<endl;
    cout<<"7 : afficher l'histogramme couleurs"<<endl;
    cout<<"8 : Augmenter le contrast d'une image selon un facteur choisi"<<endl;
    cout<<"9 : Diminuer le contrast d'une image selon un facteur choisi"<<endl;
    cout<<"10 : Augmenter la luminoste d'une image selon un facteur choisi "<<endl;
    cout<<"11 : Diminuer la luminoste d'une image selon un facteur choisi "<<endl;
    cout<<"12 : Rogner l'image en bas en supprimant nb lignes souhaite's"<<endl;
    cout<<"13 : Rogner l'image en haut en supprimant nb lignes souhaite's"<<endl;
    cout<<"14 : Rogner l'image a' droite en supprimant nb colonnes souhaite's"<<endl;
    cout<<"15 : Rogner l'image a' gauche en supprimant nb colonnes souhaite's"<<endl;
    cout<<"16 : Rotation 90° de l'image vers la droite"<<endl;
    cout<<"17 : Rotation 90° de l'image vers la gauche"<<endl;
    cout<<"18 : Retournement de l'image selon l'axe horiental"<<endl;
    cout<<"19 : Retournement de l'image selon l'axe vertical"<<endl;
    cout<<"20 : Agrandir l'image selon un facteur donne'"<<endl;
    cout<<"-1 : STOP "<<endl;
    cout << "Choix = ";
    saisieChoix(choix);//choix doit etre une des valeurs proposées au menu
    cout<<endl;
}

void reponseMenu(int choix, Image &imageCreee)
//reponse au choix effectué selon le menu en appelant le pack convenable
{
    switch (choix)
    {
    case 1:
        imageCreee.afficheImage();
        break;
    case 2:
        imageCreee = imageCreee.composanteRouge();
        break;
    case 3:
        imageCreee.packDetection();
        break;
    case 4:
        imageCreee =  imageCreee.niveauxGris();;
        break;
    case 5:
        imageCreee = imageCreee.packNoirETBlanc();
        break;
    case 6:
        afficheVect1D(imageCreee.histogrammeGris());
        break;
    case 7:
        afficheVect3D(imageCreee.histogrammeCouleur());
        break;
    case 8:
        imageCreee = imageCreee.packContrastUp();
        break;
    case 9:
        imageCreee = imageCreee.packContrastDown();
        break;
    case 10:
        imageCreee = imageCreee.packLuminosityUP();
        break;
    case 11:
        imageCreee = imageCreee.packLuminosityDown();
        break;
    case 12:
        imageCreee = imageCreee.packRognerB();
         break;
    case 13:
        imageCreee = imageCreee.packRognerH();
         break;
    case 14:
        imageCreee = imageCreee.packRognerG();
         break;
    case 15:
        imageCreee = imageCreee.packRognerD();
        break;
    case 16:
        imageCreee = imageCreee.rotationD();
        break;
    case 17:
        imageCreee = imageCreee.rotationG();
        break;
    case 18:
        imageCreee = imageCreee.retournementH();
        break;
    case 19:
        imageCreee = imageCreee.retournementV();
        break;
    case 20:
        imageCreee = imageCreee.packAggrandissement();
    case -1:
        cout<<"programme arrete";
        break;
    default:
        cout<<"choix invalide";
        break;
    }
}
