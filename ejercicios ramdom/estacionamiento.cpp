#include <iostream>

using namespace std;

int main(){

int horas, minutos;
double total;

cout << "ingrese su cantidad en horas: " ;
cin >>horas ;

cout << "ingrese su cantidad en minutos: " ;
cin >> minutos ;

if (minutos > 0)
{

 horas ++;


}
 
total = horas * 3.50;

cout << " el total a pagar es: " << total<< endl;

return 0;
}