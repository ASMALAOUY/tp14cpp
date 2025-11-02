#include <iostream>

using namespace std;
class MontantInvalideException :public exception{

   private :
    string message;
public :

  MontantInvalideException (const string&msg){
  this->message=msg;
  }
  const char*what()const noexcept override {
        return message.c_str();
    }

};
class SoldeInsuffisantException :public exception{

private:
    string message;

public:

    SoldeInsuffisantException(const string& msg){

    this->message=msg;
    }
    const char * what() const noexcept override{
     return message.c_str();
    }
};





class Compte{
private :
    int solde ;

public :
   Compte(int solde){
       this ->solde =solde;

   }
  void  deposer(int montant){
   if(montant<=0){
    throw MontantInvalideException("depot negatif ou nul !");
   }
     solde +=montant;
   cout <<"depot de :"<<montant <<" effectue. Nouveau solde : " << solde << " DH." << endl;

   }
   void  retirer(int montant){
   if(montant>solde){
    throw SoldeInsuffisantException("Solde Insuffisant pour un retrait de" );

   }

   solde -=montant;
    cout << "Retrait de " << montant << " effectue. Nouveau solde : " << solde << " DH." << endl;
   }
   int getSolde() const {
        return solde;
    }


};
int main() {
    try {
        Compte c(500);

        try {
            c.deposer(200);
            c.retirer(100);
            c.retirer(700);
        }
        catch (const SoldeInsuffisantException& e) {
            cerr << "Erreur : " << e.what() << endl;
        }

        try {
            c.deposer(-50);
        }
        catch (const MontantInvalideException& e) {
            cerr << "Erreur : " << e.what() << endl;
        }

        cout << "Solde final : " << c.getSolde() << " DH" << endl;
    }
    catch (const exception& e) {
        cerr << "Erreur inattendue : " << e.what() << endl;
    }

    return 0;
}
