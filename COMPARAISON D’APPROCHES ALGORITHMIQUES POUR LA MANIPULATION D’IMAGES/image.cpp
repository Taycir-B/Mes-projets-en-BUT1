#include "image.h"
#include "sous-programmes_externes.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <string>
using namespace std;

///classe image
//-------Constructeurs
//construire une image à partir des composantes rouge, vert et bleu
Image::Image(vector<vector<int>> &rouge, vector<vector<int>> &vert,
             vector<vector<int>> &bleu)
{
    if (!tableauxMemeTailles(rouge, vert, bleu))
        throw invalid_argument(
            "Les dimensions des tableaux ne sont pas identiques");
    cout<<"Creation d'une image"<<endl;
    _largeur = rouge.size(); //largeur = nb lignes
    _longueur = rouge[0].size();//longueur = nb colonnes
    _rouge = rouge;
    _vert = vert;
    _bleu = bleu;
}
//construire une image à partir d'un fichier ppm
Image::Image(const string& nomImage)
{
    vector<vector<int>> rouge;
    vector<vector<int>> vert;
    vector<vector<int>> bleu;
    loadPicture(nomImage,rouge,vert,bleu);
    _largeur = rouge.size();
    _longueur = rouge[0].size();
    _rouge = rouge;
    _vert = vert;
    _bleu = bleu;
}



///Methodes

//affiche l'image
void Image::afficheImage() const
{
    if(_largeur == 0 || _longueur == 0)//composantes vides = image vide
        cout<<"image vide"<<endl;
    else{
        cout<<"Affichage de l'image"<<endl;
        for (int i = 0; i < _largeur; i++)
        {
            for (int j=0; j< _longueur; j++)
                cout<<"("<<_rouge[i][j]<<", "<<_vert[i][j]<<",  "<<_bleu[i][j]<<")\t";
            cout<<endl;
        }
        cout<<endl;
    }
}


//recupere le pixel RVB das l'image à une position donné
vector<int> Image::getPixel(int i, int j)const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<int> pixel = {_rouge[i][j],_vert[i][j],_bleu[i][j]};
    return pixel;
}

//recupere le vecteur Rouge de l'image
vector<vector<int>> Image::getRed()const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    return _rouge;
}

//recupere le vecteur Vert de l'image
vector<vector<int>> Image::getGreen()const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    return _vert;
}

//recupere le vecteur Bleu de l'image
vector<vector<int>> Image::getBlue()const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    return _bleu;
}

//creer une nouvelle image rouge et noir
Image Image::composanteRouge()const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>> rougeN;
    //composantes non rouge initialisées à 0
    vector<vector<int>> vertN(_largeur, vector<int>(_longueur, 0));
    vector<vector<int>> bleuN(_largeur, vector<int>(_longueur, 0));
    rougeN = _rouge;
    Image nouvelleImage(rougeN, vertN, bleuN);
    cout<<"image transformée en rouge et noir"<<endl;
    return nouvelleImage;
}

//verifier si un pixel donné fait parte de l'image
bool Image::detection(int R, int V, int B)const
{
     //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    cout<<"Detection si le pixel ("<<R<<","<<V<<","<<B<<") existe: ";
    bool trouve = false;
    int i = 0,j;
    //recherche du pixel dans l'image
    while(!trouve && i<_largeur){
        j=0;//j commpteur des colonnes //longueur = nb colonnes
        while(!trouve && j<_longueur){
            trouve = ((_rouge[i][j]==R) && (_vert[i][j]==V) && (_bleu[i][j]==B));
            j++;
        }
        i++;
    }
    return trouve;
}

//creer une image gris
Image Image::niveauxGris()const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>>gris=_rouge;//initialiser la taille
    int couleur;
    for(int i=0; i<_largeur; i++){
        for(int j=0; j<_longueur; j++){
            couleur = (_rouge[i][j] + _vert[i][j] + _bleu[i][j])/3;
            gris[i][j]=couleur;
        }
    }
    Image imageGris(gris,gris,gris);
    cout<<"image transformée en gris "<<endl;
    return imageGris;
}

//creer une image noirETBlanc
Image Image::noirETBlanc(int seuil)const
{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    Image image  = niveauxGris();//initialiser l'image en une image gris
    vector<vector<int>>noirBlanc=_rouge;//vecteur2D(represente les composantes de l'image rouge, vert, bleu)
    for(int i=0; i<_largeur; i++){
        for(int j=0; j<_longueur; j++){
            if((image.getPixel(i,j)[0])>seuil)//plus clair => blanc{
                noirBlanc[i][j] = 255;
            else//plus sombre => noir
                noirBlanc[i][j]=0;
        }
    }
    Image imageNoirBlanc(noirBlanc,noirBlanc,noirBlanc);
    return imageNoirBlanc;
}


//donner l'histogramme Gris de l'image
vector<int> Image::histogrammeGris()const
{
    cout<<"l'histogramme Gris de l'image"<<endl;
    int gris;
    vector<int> statistiqueGris (256, 0);//Un niveau de gris est une valeur entre 0 et 255
    for(int i = 0; i<_largeur; i++)
        for(int j = 0; j < _longueur; j++)
        {
            gris = (_rouge[i][j] + _vert[i][j] + _bleu[i][j])/3;//calculons le niveau i du gris de chaque pixel
            statistiqueGris[gris] += 1;
        }
    return statistiqueGris;
}


//donner l'hiqtogramme des couleur de l'image
vector<vector<vector<int>>> Image::histogrammeCouleur()const
{
    cout<<"l'histogramme couleur de l'image"<<endl;
    vector<vector<vector<int>>> statistiqueCouleur(256, vector<vector<int>>(256,vector<int>(256,0)));//initialisation du vecteur3D à 0
    int r, v, b;
    for (int i = 0; i < _largeur; ++i){
        for (int j = 0; j < _longueur; ++j){
            r = _rouge[i][j];
            v = _vert[i][j];
            b = _bleu[i][j];
            statistiqueCouleur[r][v][b]++;
        }
    }
    return statistiqueCouleur;
}


//creer une image avec une luminosité plus haute selon un facteur donné
Image Image::luminosityUp(float facteurLuminositeUp) const
{
     //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>> rouge = _rouge;
    vector<vector<int>> vert = _rouge;
    vector<vector<int>> bleu = _rouge;
    for (int i = 0; i < _largeur; i++){
        for (int j = 0; j < _longueur; j++){
            rouge[i][j] = _rouge[i][j] * facteurLuminositeUp;
            vert[i][j] = _vert[i][j] * facteurLuminositeUp;
            bleu[i][j] = _bleu[i][j] * facteurLuminositeUp;
            if (rouge[i][j] > 255)
                rouge[i][j] = 255;
            if (vert[i][j] > 255)
                vert[i][j] = 255;
            if (bleu[i][j] > 255)
                bleu[i][j] = 255;
        }
    }
    Image imageLuminosityUp(rouge, vert, bleu);
    return imageLuminosityUp;
}


//creer une image avec une luminosité moins haute selon un facteur donné
Image Image::luminosityDown(float facteurLuminositeDown) const
{
     //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>> rouge = _rouge;
    vector<vector<int>> vert = _rouge;
    vector<vector<int>> bleu = _rouge;
    for (int i = 0; i < _largeur; i++){
        for (int j = 0; j < _longueur; j++){
            rouge[i][j] = _rouge[i][j] * facteurLuminositeDown;
            vert[i][j] = _vert[i][j] * facteurLuminositeDown;
            bleu[i][j] = _bleu[i][j] * facteurLuminositeDown;
            if (rouge[i][j] < 0)
                rouge[i][j] = 0;
            if (vert[i][j] < 0)
                vert[i][j] = 0;
            if (bleu[i][j] < 0)
                bleu[i][j] = 0;
        }
    }
    Image imageLuminosityDown(rouge, vert, bleu);
    return imageLuminosityDown;
}

//creer une image avec un contraste plus haut selon un facteur donné
Image Image::contrastUp(float facteur)const
{   //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>>rougeN=_rouge;
    vector<vector<int>>bleuN=_bleu;
    vector<vector<int>>vertN=_vert;
    float contrastRouge, contrastVert, contrastBleu;
    for (int i = 0; i < _largeur; i++){
        for (int j = 0; j < _longueur; j++){
            contrastRouge = (_rouge[i][j] * facteur) - 128;
            contrastVert = (_vert[i][j] * facteur) - 128;
            contrastBleu = (_vert[i][j] * facteur) - 128;
            contrastAppliqueComposante(rougeN, i, j, contrastRouge);//rouge
            contrastAppliqueComposante(vertN, i, j, contrastVert);//vert
            contrastAppliqueComposante(bleuN, i, j, contrastBleu);//bleu
        }
    }
    Image imageContraste(rougeN, vertN, bleuN);
    return imageContraste;
}


//creer une image avec un contraste moin haut selon un facteur donné
Image Image::contrastDown(float facteur)const
{
     //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide");
    vector<vector<int>>rougeN=_rouge;
    vector<vector<int>>bleuN=_bleu;
    vector<vector<int>>vertN=_vert;
    float contrastRouge, contrastVert, contrastBleu;
    for (int i = 0; i < _largeur; i++){
        for (int j = 0; j < _longueur; j++){
            contrastRouge = (_rouge[i][j] * facteur) - 128;
            contrastVert = (_vert[i][j] * facteur) - 128;
            contrastBleu = (_vert[i][j] * facteur) - 128;
            contrastAppliqueComposante(rougeN, i, j, contrastRouge);//rouge
            contrastAppliqueComposante(vertN, i, j, contrastVert);//vert
            contrastAppliqueComposante(bleuN, i, j, contrastBleu);//bleu
        }
    }
    Image imageContraste(rougeN, vertN, bleuN);
    return imageContraste;
}


//********MenuFichiers****
// question3
// creer un fichier image au format ppm à partir d’un objet de la classe image.
void Image::ecrireFichierPPM(ofstream& o)const
{
    string nomFichierImage;
    saisiNomEnregistrementPPM(nomFichierImage);//nom fichier choisi par l'utlisateur respesctant le format .ppm
    try{
        o.open(nomFichierImage);
        if(!(o.is_open()))
            throw invalid_argument ("probleme!Le fichier n'a pas pu etre créé");
        o << "P3"<<endl;
        o << "# Created by GIMP version 2.10.28 PNM plug-in"<<endl;
        o << _largeur << endl;
        o << _longueur << endl;
        o <<255<<endl;
        for (int i = 0; i < _largeur; i++){
            for (int j=0; j< _longueur; j++){
                o << _rouge[i][j] << endl;
                o << _vert[i][j]<<endl;
                o << _bleu[i][j]<<endl;
            }
        }
        o<<endl;
        o.close();
        cout<<"fichier "<<nomFichierImage<<" bien cree :) "<<endl;
    }
    catch(const invalid_argument &e){
        cerr<<e.what();
    }
}
//***********************GeometrieTaille*******
//---question1
//Méthode utilitaire pour redimensionner les composantes => rogner
void Image::redimensionnerComposante(vector<vector<int>> &composante, int nouvelleTaille) {
    for (int i = 0; i < _largeur; ++i) {
        composante[i].resize(nouvelleTaille);
    }
}
//rogner l'image à droite
Image Image::rognerD(int nb) const
{
    //exceptions
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    if(nb>=_longueur || nb < 0)
        throw(invalid_argument)("demande refusee: nb colonnes a' supprimer < 0 ou >=nb colonnes de l'image");
    if (nb == 0)
        return (*this);

    Image imageRognee = (*this);

        // Redimensionner les composantes de couleur
        imageRognee.redimensionnerComposante(imageRognee._rouge, _longueur - nb);
        imageRognee.redimensionnerComposante(imageRognee._vert, _longueur - nb);
        imageRognee.redimensionnerComposante(imageRognee._bleu, _longueur - nb);

        imageRognee._longueur = _longueur - nb;
        imageRognee._largeur = _largeur;
        cout << "Image Rognee :) " << endl;
        return imageRognee;
}

//rogner l'image en bas
Image Image::rognerB(int nb)const
{   //exceptions
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    if(nb>=_largeur || nb<0)
        throw(invalid_argument)("demande refusee: nb lignes a' supprimer < 0 ou >=nb lignes de l'image");
     if(nb == 0)//auccun changement(apres selection au menu, l'utilisateur a changé son avis, il peut taper 0)
        return (*this);
    Image imageRognee = (*this);//une copie de l'image originale
    // Redimensionner les composantes de couleur
        imageRognee._largeur = _largeur - nb;
        imageRognee._longueur=_longueur;
        cout << "Image Rognee :) " << endl;
        return imageRognee;

}
//rogner l'image en haut
Image Image::rognerH(int nb)const
{
    //exceptions
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    if(nb>=_largeur || nb < 0)
        throw(invalid_argument)("demande refusee: nb lignes a' supprimer < 0 ou >=nb lignes de l'image");
    if(nb == 0)//auccun changement(apres selection au menu, l'utilisateur a changé son avis, il peut taper 0)
        return (*this);//auccun changement(apres selection au menu, l'utilisateur a changé son avis, il peut taper 0)
    else{
        //initialisation des nouvelles composantes qui vont former l'image rognée
        vector<vector<int>> rougeN(_largeur-nb, vector<int>(_longueur));
        vector<vector<int>> vertN(_largeur-nb, vector<int>(_longueur));
        vector<vector<int>> bleuN(_largeur-nb, vector<int>(_longueur));
        int cpt = nb;//compteur de a ligne à décler
        for(int i = 0; (i < _largeur-nb && cpt<_largeur) ; i++){
            rougeN[i] = _rouge[cpt];
            vertN[i] = _vert[cpt];
            bleuN[i] = _bleu[cpt];
            cpt++;
        }

        Image imageRognee(rougeN, vertN, bleuN);//creation de la nouvelle image rognée
        cout<<"image Rognee :) "<<endl;
        return imageRognee;
    }

}
//rogner l'image à gauche
Image Image::rognerG(int nb)const
{   //exceptions
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    if(nb>=_longueur || nb < 0)
        throw(invalid_argument)("demande refusee: nb colonnes a' supprimer < 0 ou >=nb colonnes de l'image");
    if(nb==0)//auccun changement(apres selection au menu, l'utilisateur a changé son avis, il peut taper 0)
        return (*this);
    else{
        // Déclaration des composantes de la nouvelle image rognée
    Image imageRognee = (*this);
    int i, j;
    for (i = 0; i < _largeur; i++) {
        for (j = 0; j < (_longueur - nb) && (j + nb) < _longueur; j++){
            imageRognee._rouge[i][j] = _rouge[i][j + nb];
            imageRognee._vert[i][j] = _vert[i][j + nb];
            imageRognee._bleu[i][j] = _bleu[i][j + nb];
        }
    }
    imageRognee.redimensionnerComposante(imageRognee._rouge, _longueur - nb);
    imageRognee.redimensionnerComposante(imageRognee._vert, _longueur - nb);
    imageRognee.redimensionnerComposante(imageRognee._bleu, _longueur - nb);
    imageRognee._largeur = _largeur;
    imageRognee._longueur = _longueur - nb;
    Image imageRogneeG(imageRognee._rouge, imageRognee._vert, imageRognee._bleu);
        cout<<"image Rognee :) "<<endl;
        return imageRognee;
    }
}


//---question2 + 3 (2etoiles)
//Rotation à droite
Image Image::rotationD() const {
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    //initialiser les composantes avec la taille apres rotation largeur<->longueur
    vector<vector<int>> rougeN(_longueur, vector<int>(_largeur));
    vector<vector<int>> vertN(_longueur, vector<int>(_largeur));
    vector<vector<int>> bleuN(_longueur, vector<int>(_largeur));

    for (int i = 0; i < _longueur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
            rougeN[i][_largeur - 1 - j] = _rouge[j][i];
            vertN[i][_largeur - 1 - j] = _vert[j][i];
            bleuN[i][_largeur - 1 - j] = _bleu[j][i];
        }
    }
    Image imageRotationD(rougeN, vertN, bleuN); // Création d'une nouvelle image avec rotation droite
    return imageRotationD;
}

//Rotation à gauche
Image Image::rotationG() const {
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    //initialiser les composantes avec la taille apres rotation (image non carrée  => largeur<->longueur)
    vector<vector<int>> rougeN(_longueur, vector<int>(_largeur));
    vector<vector<int>> vertN(_longueur, vector<int>(_largeur));
    vector<vector<int>> bleuN(_longueur, vector<int>(_largeur));
    for (int i = 0; i < _longueur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
            rougeN[i][j] = _rouge[j][_longueur - 1 - i];
            vertN[i][j]= _vert[j][_longueur - 1 - i];
            bleuN[i][j] = _bleu[j][_longueur - 1 - i];
        }
    }
    Image imageRotationD(rougeN, vertN, bleuN); // Création d'une nouvelle image avec rotation droite
    return imageRotationD;
}

//---question4
//symetrie selon un axe horizental
Image Image::retournementH()const{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    vector<vector<int>> rougeN(_largeur, vector<int>(_longueur));
    vector<vector<int>> vertN(_largeur, vector<int>(_longueur));
    vector<vector<int>> bleuN(_largeur, vector<int>(_longueur));
    for(int i = 0; i < _largeur;i++){
        for(int j = 0; j < _longueur; j++){
            rougeN[i][j] = _rouge[i][(_longueur-1) - j];
            vertN[i][j] = _vert[i][(_longueur-1) - j];
            bleuN[i][j] = _bleu[i][(_longueur-1) - j];
        }
    }
    Image imageSymetrieH(rougeN, vertN, bleuN);//creation de la nouvelle image apres rotation droite
    return imageSymetrieH;
}
//symetrie selon un axe vertical
Image Image::retournementV()const{
    //exception
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    vector<vector<int>> rougeN(_largeur, vector<int>(_longueur));
    vector<vector<int>> vertN(_largeur, vector<int>(_longueur));
    vector<vector<int>> bleuN(_largeur, vector<int>(_longueur));
    for(int i = 0; i < _largeur;i++){
        rougeN[i] = _rouge[(_largeur-1) - i];
        vertN[i] = _vert[(_largeur-1) - i];
        bleuN[i] = _bleu[(_largeur-1) - i];
    }
    Image imageSymetrieV(rougeN, vertN, bleuN);//creation de la nouvelle image apres rotation gauche
    return imageSymetrieV;
}

//---question5 (2etoiles)
//aggrandir une image selon un facteur donné
Image Image::agrandissement(int facteur) const {
    //exceptions
    if(_largeur == 0 || _longueur == 0)
        throw(invalid_argument)("image vide!!");
    if(facteur <= 1)
        throw(invalid_argument)("ce facteur est <= 1 donc il ne permet pas d'aggrandir l'image");
    //initialisation des composantes avec la taille d'image aggrandite
    int largeurN = _largeur * facteur;
    int longueurN = _longueur * facteur;
    vector<vector<int>> rougeN(largeurN, vector<int>(longueurN));
    vector<vector<int>> vertN(largeurN, vector<int>(longueurN));
    vector<vector<int>> bleuN(largeurN, vector<int>(longueurN));
    //parcourir les dimensions de la nouvelle image
    //et assigner les pixels appropriés de l'image d'origine
    //aux positions correspondantes dans l'image agrandie
    for (int i = 0; i < largeurN; i++) {
        for (int j = 0; j < longueurN; j++) {
            //calculer les coordonnées correspondantes dans l'image d'origine.
            int origineI = i / facteur;//cordonnée ligne
            int origineJ = j / facteur;//cordonnée colonne
            rougeN[i][j] = _rouge[origineI][origineJ];
            vertN[i][j] = _vert[origineI][origineJ];
            bleuN[i][j] = _bleu[origineI][origineJ];
        }
    }
    Image imageAggrandit(rougeN, vertN, bleuN);//creation d'une nouvelle image aggrandite
    return imageAggrandit;
}


///Méthodes d'encapsulation
///NBGris getPixel
void Image::saisieIndicesImage(int &i, int &j){
        cout<<"donner la ligne: ";
        cin>>i;//compteur des lignes
        cout<<"donner la colonne: ";
        cin>>j;//compteur des colonnes
        //controle saisie sur les indices i,j ;
        //ils doivent correspondre à la taille de l'image
        while ((i >= _largeur && j < 0) || (j >= _longueur && j < 0)){
            cout<<"!! ligne inclus entre 0 et "<<_largeur;
            cout<<" et colonnes entre 0 et "<<_longueur<<endl;
            cout<<"donner la ligne: ";
            cin>>i;
            cout<<"donner la colonne: ";
            cin>>j;
        }
}
void Image::packGetPixel()
//retourne un vecteur à 1 dimension
//ce vecteur les composantes RVB à une position donné
{
    cout<<"get pixel:  "<<endl;
    //saisie de la position choisie du pixel
    int i, j;
    saisieIndicesImage(i,j);
    vector <int> tabGetPixel(3);//Un pixel a 3 composantes Rouge Vert Bleu
    tabGetPixel = getPixel(i, j);//extraire les composantes dns un vecteur
    cout<<"pixel position ["<<i<<"]["<<j<<"]:\t";
    afficheVect1D(tabGetPixel);
}

///NBGris detection
void Image::packDetection()
//précise si un RVB donné existe dans l'image
{
    cout<<"detection: "<<endl;
    int r, v, b;
    saisieRVB(r, v, b);
    bool trouve = detection(r,v,b);
    if(trouve)
        cout<<"("<<r<<", "<<v<<", "<<b<<") existe dans l'image"<<endl<<endl;
    else
        cout<<"("<<r<<", "<<v<<", "<<b<<") n'existe pas dans l'image"<<endl<<endl;
}
///NBGris noirETBlanc
Image Image::packNoirETBlanc()
//saisie de la seuil + retourne une image noir et blanc
{
    cout<<"image noir et blanc"<<endl;
    int seuil;
    cout<<"saisir la seuil de transformation de l'image en noir et blanc"<<endl;
    saisieComposantePixel(seuil);
    Image imageNB = noirETBlanc(seuil);
    cout<<"image bien transformée "<<endl;
    return imageNB;
}

///NBGris luminosity
//luminosityUp
Image Image::packLuminosityUP()
//retourne une image apres l'augmentation de sa luminosité
{
    cout<<"LuminosityUp: "<<endl;
    float facteurLuminosityUp;
    saisieFacteurUp(facteurLuminosityUp);
    Image imageLuminosityUp = luminosityUp(facteurLuminosityUp);
    cout<<"La luminosité a été bien augmentée "<<endl;
    return imageLuminosityUp;
}

//luminosityDown
Image Image::packLuminosityDown()
//retourne une image apres dimunition de sa luminosité
{
    cout<<"LuminosityDown: "<<endl;
    float facteurLuminosityDown;
    saisieFacteurDown(facteurLuminosityDown);
    Image imageLuminosityDown = luminosityDown(facteurLuminosityDown);
    cout<<"La luminosité a été bien diminuée "<<endl;
    return imageLuminosityDown;
}


///NBGris contrast
//contrastUp
Image Image::packContrastUp()
//retourne une image apres l'augmentation de son contraste
{
    cout<<"ContrastUp: "<<endl;
    float facteurContrastUp;
    saisieFacteurUp(facteurContrastUp);
    Image imageContrastUp = contrastUp(facteurContrastUp);
    cout<<"Le contraste a été bien augmenté"<<endl;
    return imageContrastUp;
}
//contrastDown
Image Image::packContrastDown()
//retourne une image apres la diminution de son contraste
{
    cout<<"ContrastDown: "<<endl;
    float facteurContrastDown;
    saisieFacteurDown(facteurContrastDown);
    Image imageContrastDown = contrastDown(facteurContrastDown);
    cout<<"Le contraste a été bien diminué"<<endl;
    return imageContrastDown;
}
//***********MenuFichier************
void Image::packCreerFichier()
//cree un fichier ppm correspondant à l'image cible
{
    cout<<"transformer l'objet image en fichier ppm"<<endl;
    ofstream sortie;
    ecrireFichierPPM(sortie);
}

//***********GeometrieTaille*************
///rogner l'image
//Chaque packRogner permet de saisir de nb lignes/colonnes à supprimer + retourner l'image rognée
//si l'image est petite (nblignes/nbcolonnes =1) la meme image est renvoyée (sans modifications)
//on a pas utilisé d'exception sur ce cas pour ne pas arreter tous le programme
//pour que le menu continue à proposer les autres operations disponibles

//rogner bas
Image Image::packRognerB()const{
    cout<<"Vous avez demandez de rogner l'image en bas"<<endl;
    int nb = 0;
    saisieNbLignesRogner(nb, getLargeur());//controle de saisie sur nb lignes à supprimer
    //si l'image est trop petite nb ne change pas de valeur(nb=0)
    //sinon nb doit etre entre 1 et nb lignes de l'image cible
    return rognerB(nb);;
}
//rogner haut
Image Image::packRognerH()const{
    cout<<"Vous avez demandez de rogner l'image en haut"<<endl;
    int nb = 0;
    saisieNbLignesRogner(nb, getLargeur());
    //si l'image est trop petite nb ne change pas de valeur(nb=0)
    //sinon nb doit etre entre 1 et nb lignes de l'image cible
    return rognerH(nb);
}
//rogner droite
Image Image::packRognerD()const{
    cout<<"Vous avez demandez de rogner l'image a' droite"<<endl;
    int nb = 0;
    saisieNbColonnesRogner(nb, getLongueur());
    //si l'image est trop petite nb ne change pas de valeur(nb=0)
    //sinon nb doit etre entre 1 et nbcolonnes de l'image cible
    return rognerD(nb);
}
//rogner gauche
Image Image::packRognerG()const{
    cout<<"Vous avez demandez de rogner l'image a' gauche"<<endl;
    int nb = 0;//par defaut nb prend 0 pour ne pas
    saisieNbColonnesRogner(nb, getLongueur());
    //si l'image est trop petite nb ne change pas de valeur(nb=0)
    //sinon nb doit etre entre 1 et nbcolonnes de l'image cible
    return rognerG(nb);;
}

///aggrandir l'image
//saisie du facteur d'aggrandissement + retourner l'image aggrandit
Image Image::packAggrandissement()const{
    cout<<"vous avez demand' d'agrandir l'image"<<endl;
    int facteur;
    saisieFacteurAggrandir(facteur);//saisie d'un facteur > 1
    return agrandissement(facteur);
}
