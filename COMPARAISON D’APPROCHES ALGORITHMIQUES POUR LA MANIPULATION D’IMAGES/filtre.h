#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "image.h"
using namespace std;

class Filtre
{
    vector<vector<float>> _action;
    int _rayon;
public:
    Filtre (const vector<vector<float>> & matricefiltre, int _rayon);
    Image application(const Image & image)const;
};

#endif // FILTRE_H_INCLUDED
