#ifndef NBGRIS_H_INCLUDED
#define NBGRIS_H_INCLUDED

#include "image.h"
#include <iostream>
#include <vector>
using namespace std;

///constantes
const int MAXFONCTIONNALITES = 20; //le nombre de fonctionnalit� disponibles au menu
const int STOP = -1;


///prototypes
//saisir un choix figurant sur le menu
void saisieChoix(int &choix);

//afficher un menu des operations/modifications possible � effectuer sur une image
void menu(int &choix);

//repond au choix effectu� au menu en effectuant les operations/modifications demand�es
void reponseMenu(int choix, Image &imageCreee);

#endif
