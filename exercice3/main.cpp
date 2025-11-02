#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>


using namespace std;
void lireFichier(const string nomFichier)
{
    ifstream fichier(nomFichier);
    if (!fichier.is_open()){
        throw runtime_error(" impossible d ouvrir le fichier \""+nomFichier+"\"");
    }

    string ligne;
    cout << "Contenu du fichier \"" << nomFichier << "\" :" << endl;

 while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }
  fichier.close();

}
int main()
{
    try{
    lireFichier("test.txt");

    lireFichier("data.txt");

    }catch( const exception& e){
    cerr<<"Erreur : "<<e.what()<<endl;

    }
    return 0;
}
