#ifndef NBGRIS_H_INCLUDED
#define NBGRIS_H_INCLUDED

#include "image.h"
#include <iostream>
#include <vector>
using namespace std;

///constantes
const int MAXFONCTIONNALITES = 20; //le nombre de fonctionnalité disponibles au menu
const int STOP = -1;


///prototypes
//saisir un choix figurant sur le menu
void saisieChoix(int &choix);

//afficher un menu des operations/modifications possible à effectuer sur une image
void menu(int &choix);

//repond au choix effectué au menu en effectuant les operations/modifications demandées
void reponseMenu(int choix, Image &imageCreee);

#endif
