#include <iostream>
#include <vector>
#include "image.h"
#include "menu.h"
#include "sous-programmes_externes.h"
using namespace std;
int main() {
    //permettre à l'utilisateur de créer un objet image à partir des fichiers ppm
    Image imageCreee = packCreerImage();

    //phrases explicatives pour l'utilisateur
    cout<<endl<<"vous avez la main pour faire des modifications sur l'image"<<endl;
    cout<<"Apres toutes les modifications, l'image sera enregistree dans un fichier.ppm"<<endl;
    cout<<"Si vous ne realisez aucunes modifications, l'image originale sera enregistree"<<endl<<endl;

    //permettre à l'utilisateur d'effectuer des opérations/modification sur l'image
    int choix;
    menu(choix);
    while(choix != STOP)
    {
        reponseMenu(choix, imageCreee);//répondre à la demande de l'utilisateur (modifications/opérations)
        menu(choix);//proposer le menu des operations/modifications jusqu'à saisie du STOP
    }
    //enregistrer l'image dans un fichier ppm apres les modifications
    imageCreee.packCreerFichier();
    return 0;
}
