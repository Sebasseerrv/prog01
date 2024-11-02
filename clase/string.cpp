#include <iostream>
#include <locale.h>
using namespace std;


int main()
{
   string frase;

   cout<<"ingrese frase: "<<endl;
   cin.ignore();
   getline(cin, frase);  


   for (int i=frase.size()-1;i>=0; i--)
   {
    cout<<frase[i];
   }
   
    return 0;
}
