#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "filtre.h"
#include "image.h"
using namespace std;


Filtre::Filtre(const vector<vector<float>> & matricefiltre, int rayon){
    if ((rayon*2)+1!=matricefiltre.size() && (rayon*2)+1!=matricefiltre[0].size())
        throw invalid_argument("les dimensions de la matrice ne sont pas cohérentes avec le rayon");
    _action = matricefiltre;
    _rayon = rayon;
}

Image Filtre::application(const Image & image)const{
    vector<vector<int>> rouge = image.getRed();
    vector<vector<int>> vert = image.getGreen();
    vector<vector<int>> bleu = image.getBlue();
    for(int i=0; i<image.getRed().size();i++){
        for(int j=0;j<image.getRed()[i].size();j++){
            for (int k=0;k<(_rayon*2)+1;k++){
                for(int l =0;l<(_rayon*2)+1;l++){
                    if (k-_rayon>=0 && l-_rayon>=0 && k+_rayon<rouge.size() && l+_rayon<rouge[i].size()){
                    rouge[i][j]+=_action[k][l]*image.getRed()[k-_rayon][l-_rayon];
                    vert[i][j]+=_action[k][l]*image.getGreen()[k-_rayon][l-_rayon];
                    bleu[i][j]+=_action[k][l]*image.getBlue()[k-_rayon][l-_rayon];}
                }
            }
        }
    }
    Image Imagefinale(rouge,vert,bleu);
    return Imagefinale;
}
