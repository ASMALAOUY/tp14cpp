#include <iostream>
#include <stdexcept>

using namespace std;

double diviser(int a, int b){
    if(b==0){
    throw runtime_error("division par zero interdite!");
    }

  return (a)/b;

  }

int main()
{   try{
    cout <<"Resultat :"<<diviser(10,2)<<endl;
    cout<<"Resultat :" <<diviser(10,0)<<endl;
   }catch(const exception& e){
     cerr<<"Erreur:"<< e.what()<<endl;

   }

    return 0;
}
