#include "image.h"
#include "sous-programmes_externes.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <string>
using namespace std;
///fonctions externes
//************NBGris************
void afficheVect3D(const vector<vector<vector<int>>> &tab3D)
//affiche un vecteur 3D
{
    if(tab3D.size()==0)
        cout<<"tableau vide"<<endl;
    else{
        for(int r=0; r</*tab3D.size()*/10; r++){
            for (int v = 0; v </*  tab3D[r].size()*/ 10; v++){
                for (int b = 0; b < /*tab3D[r][v].size()*/ 10; b++)
                    cout << "Histogramme Couleur [" << r << "][" << v << "][" << b << "] : " << tab3D[r][v][b]<<endl;
            }
            cout<<endl;
        }
    }
}

void afficheVect2D(const vector<vector<int>> &tab2D)
//affiche un vecteur 2D
{
    if(tab2D.size()==0)
        cout<<"tableau vide"<<endl;
    else{
        for (int i = 0; i < tab2D.size(); i++)
            afficheVect1D(tab2D[i]);
        cout<<endl;
    }

}

void afficheVect2Dfloat(const vector<vector<float>> &tab2D)
//affiche un vecteur 2D
{
    if(tab2D.size()==0)
        cout<<"tableau vide"<<endl;
    else{
        for (int i = 0; i < tab2D.size(); i++)
            for (int j=0;j<tab2D[i].size();j++)
                cout<<tab2D[i][j];
        cout<<endl;
    }

}
void afficheVect1D(const vector <int> & tab)
//affiche un vecteur 1D
{
    if(tab.size()==0)
        cout<<"tableau vide"<<endl;
    else{
        for (int i=0; i<tab.size(); i++)
            cout<<tab[i]<<" ";
        cout<<endl;
    }

}

///Pour getPixel
void saisieComposantePixel(int &x)
//saisie d'une valeur entre 0 et 255
{
    cout<<"entier entre 0 et 255: ";
        cin>>x;
        while(x < 0 || x >255){
            cout<<"Le degre' doit etre entre 0 et 255!! ";
            cin>>x;
        }
}
///pour ContrastUP/ContrastDown et LuminosityUp/luminosityDown
void saisieFacteurUp(float &facteurUp)
//saisir un reel facteur d'augmentation de contrast/luminosite supérieur à 1
{
    cout<<"donner le facteur d'augmentation (reel > 1) ";
    cin>>facteurUp;
    while(facteurUp <= 1)
    {
        cout<<"erreur! veuillez saisir une valeur superieur a 1"<<endl;
        cin>>facteurUp;
    }
}

void saisieFacteurDown(float &facteurDown)
//saisir un facteur de diminution de contrast/luminosite inférieur à 1
{
    cout<<"donner le facteur de dimunition (reel < 1)";
    cin>>facteurDown;
    while(facteurDown >= 1)
    {
        cout<<"erreur! veuillez saisir une valeur superieur a 1"<<endl;
        cin>>facteurDown;
    }
}
//*****************MenuFichiers**************
//---question 2
///pour construire un objet image à partir  d'un fichier ppm
Image packCreerImage()
//retourne une mage creee à partir d'un fichier ppm donné
{
    cout<<"creer un objet image à partir d'un fichier ppm"<<endl;
    string nomFichierImage;
    saisiNomImagePPM(nomFichierImage);//Saisir le nom du fichier image sur lequel l’utilisateur veut travailler
    Image imagePPM(nomFichierImage);//construire l'objet image à partir du fichier Image ppm
    return imagePPM;
}
void saisiNomImagePPM(string &nomImage)
//saisir le nom du fichier image à ouvirir au format .ppm
{
    cout<<"Veuillez entrer le nom du fichier a' creer, au format nomchoisi.ppm "<<endl;
    cout<<"(Couleur.ppm, Flowerbed-small.ppm, Flowerbed-large.ppm, Ara_ararauna.ppm, Mandel.ppm, Procyon_lotor.ppm): ";
    cin>>nomImage;
    int longueur = nomImage.length();
    while(longueur <= 4 || nomImage[longueur-1] != 'm' || nomImage[longueur - 2] != 'p'|| nomImage[longueur - 3] != 'p' || nomImage[longueur - 4] != '.')
    {
        cout<<" !! respectez le format nomChoisi.ppm ";
        cin>>nomImage;
        longueur = nomImage.length();
    }
}
void saisiNomEnregistrementPPM(string &nomImage)
//saisir le nom du fichier dans lequel les modificaions seront enregistrés (image au format .ppm)
{
    cout<<"Veuillez entrer le nom du fichier a' creer, au format nomchoisi.ppm "<<endl;
    cin>>nomImage;
    int longueur = nomImage.length();
    while(longueur <= 4 || nomImage[longueur-1] != 'm' || nomImage[longueur - 2] != 'p'|| nomImage[longueur - 3] != 'p' || nomImage[longueur - 4] != '.')
    {
        cout<<" !! respectez le format nomChoisi.ppm ";
        cin>>nomImage;
        longueur = nomImage.length();
    }
}

void loadPicture(const string &picture, vector<vector<int>> &red,
                 vector<vector<int>> &green,
                 vector <vector<int>> &blue)
{
    // Declaration des variables
    string line; // pour recuperer les lignes du fichier image au format .ppm, qui est code en ASCII.
    string format; //pour recuperer le format de l'image : celui-ci doit être de la forme P3
    string name; // au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    //cout<<"il faut choisir une image de {Ara_ararauna.ppm, Couleur.ppm, Flowerbed-large.ppm, Flowerbed-small.ppm, Mandel.ppm, Procyon_lotor.ppm}: ";
    int taille;
    vector <int> mypixels; // pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants
    ifstream entree; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    int hauteur; // pour bien verifier que l'image est carree, et de taille respectant les conditions fixees par l'enonce
    // Initialisation des variables
    name = picture;
    // Permet d'ouvrir le fichier portant le nom picture
    // ouverture du fichier portant le nom picture
    entree.open(name);
    // On verifie que le fichier a bien ete ouvert. Si cela n'est pas le cas, on redemande un nom de fichier valide
    while (!entree)
    {
        //cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        entree.open(name); // relance
    }
    // Lecture du nombre definissant le format (ici P3)
    entree >> format;
    // on finit de lire la ligne (caractere d'espacement)
    getline(entree, line);
    // Lecture du commentaire
    getline(entree, line);
    //lecture des dimensions
    entree >> taille >> hauteur;
    getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    // On verifie que l'image a une taille qui verifie bien les conditions requises par l'enonce.
    // Si cela n'est pas le cas, on redemande un fichier valide, et ce, tant que necessaire.
    while (format != "P3")
    {
        if (format != "P3")
        {
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }
        entree.close();
        // On va redemander un nom de fichier valide.
        do
        {
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm." << endl;
            cin >> name;
            entree.open(name); // relance
        }
        while(!entree);
        // Lecture du nombre definissant le format (ici P3)
        entree >> format;
        getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
        // Lecture du commentaire
        getline(entree, line);
        //lecture des dimensions
        entree >> taille >> hauteur; // relance
        getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    }
    //Lecture de la valeur max
    getline(entree, line);
    //Lecture des donnees et ecriture dans les tableaux :
    // Pour plus de simplicite, on stocke d'abord toutes les donnees dans mypixels
    // dans l'ordre de lecture puis ensuite on les repartira dans les differents tableaux.
    //Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
    // Il faudra donc repartir les valeurs R correspondant a la composante rouge de l'image
    // dans le tableau red, de même pour G et B.
    int pix;
    mypixels.resize(3*taille*hauteur); // taille fixe : on alloue une fois pour toutes
    for (int i = 0; i < 3*taille*hauteur; i++)
    {
        entree >> pix;
        mypixels[i]=pix;
    }
    // Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les bonnes composantes
    // Comme dans mypixels, les donnees sont stockees de la maniere suivante : RGB RGB RGB, il faut mettre
    // les valeurs correspondant a la composante rouge dans red, ...
    // Ainsi, les valeurs de la composante rouge correspondent aux valeurs stockes aux indices
    // congrus a 0 mod 3 dans mypixels, que les valeurs de la composante verte correspond aux valeurs
    // stockes aux indices sont congrus a 1 mod 3, ...
    // les valeurs d'une ligne
    int val;
    red.resize(hauteur);
    green.resize(hauteur);
    blue.resize(hauteur);
    for (int i = 0; i < hauteur; i++)
    {
        vector <int> ligneR(taille);
        vector <int> ligneB(taille);  // les lignes ont toutes la même taille
        vector <int> ligneG(taille);
        for (int j = 0; j < taille; j++)
        {
            val =  mypixels[3*j + 3*taille*i];
            ligneR[j]=val;
            val = mypixels[3*j + 1 + 3*taille*i];
            ligneG[j]=val;
            val = mypixels[3*j + 2 + 3*taille*i];
            ligneB[j]=val;
        }
        red[i]=ligneR;
        green[i]=ligneG;
        blue[i]=ligneB;
    }
    // Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
    entree.close();
}
//***********GeometrieTaille.pdf**********
///pour rogner l'image
//saisie d'un nombre > 0 et < nombre de colonnes
void saisieNbColonnesRogner(int &nb, int longueur){
    if(longueur == 1)
        cout<<"l'image ne peut pas etre rognee car elle risque de s'effacer"<<endl;
    else{
        //saisir un nombre > 0 et < nombre de colonnes
        cout << "donner le nombre de colonnes a' supprimer  (entier >0 et < "<<longueur -1<<" : ";
        cin>>nb;
        while(nb >= longueur|| nb <= 0){
            cout << "saisir un nombre compris entre 1 et "<<longueur -1<<" : ";
            cin>>nb;
        }
    }
}
//saisie d'un nombre > 0 et < nombre de lignes
void saisieNbLignesRogner(int &nb, int largeur){
    if(largeur == 1)
        cout<<"l'image ne peut pas etre rognee car elle risque de s'effacer"<<endl;
    else{
        cout << "donner le nombre de lignes a' supprimer (entier entre 1 et "<<largeur-1<<":  ";
        cin>>nb;
        while(nb >= largeur || nb <= 0){
            cout << "!! saisir un nombre compris entre 1 et "<<largeur-1<<" : ";
            cin>>nb;
        }
    }
}
///pour aggrandir l'Image
void saisieFacteurAggrandir(int &facteurAggrandir)
//saisir un entier facteur d'agrandissement
{
    cout<<"donner le facteur d'augmentation (reel > 1)";
    cin>>facteurAggrandir;
    while(facteurAggrandir <= 1)
    {
        cout<<"erreur! veuillez saisir une valeur superieur a 1"<<endl;
        cin>>facteurAggrandir;
    }
}
void saisieRVB(int &r, int &v, int &b){
    cout<<" donner le degré de R: ";
    saisieComposantePixel(r);
    cout<<" donner le degré de V: ";
    saisieComposantePixel(v);
    cout<<" donner le degré de B: ";
    saisieComposantePixel(b);
}
 void contrastAppliqueComposante(vector<vector<int>> &composante, int i, int j, float contrastCalcule){
    if (contrastCalcule > 255)
        composante[i][j] = 255;
    else if (contrastCalcule < 0)
        composante[i][j] = 0;
    else
        composante[i][j] = contrastCalcule;
}
int tableauxMemeTailles(const vector<vector<int>> &tab1, const vector<vector<int>> &tab2, const vector<vector<int>> &tab3){
        bool verif_ligne = false;
        bool verif_colonne = true;
        verif_ligne = ((tab1.size() == tab2.size()) && (tab2.size() == tab3.size()));
        int i = 0;
        while (verif_colonne && verif_ligne && i < tab1.size())
        {
            verif_colonne = ((tab1[i].size() == tab2[i].size()) &&
                             (tab2[i].size() == tab3[i].size()));
            i++;
        }
        return verif_colonne&&verif_ligne;
}
