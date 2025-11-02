#include <iostream>
#include <stdexcept>
using namespace std;


class StockInsuffisantException :public exception{
private :
    string message;
public :

  StockInsuffisantException(const string&msg){
  this->message=msg;
  }
  const char*what()const noexcept override {
        return message.c_str();
    }
};

class Produit {
private:
    int stock;

public:

   Produit(int stock){
   this->stock=stock;
   }

   void vendre(int quantite){
    if(quantite>stock){
     throw StockInsuffisantException("la quantite demandee depasse le stock disponible");
    }
    stock-=quantite;
    cout << "Vente reussie. Stock restant : " << stock << endl;
   }

};


int main()
{  try{

    Produit p(10);
    p.vendre(2);
    p.vendre(9);
}catch(const exception& e){
    cerr <<"Erreur: "<<e.what()<<endl;

}

    return 0;
}
