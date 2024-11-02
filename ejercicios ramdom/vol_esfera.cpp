#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int radio, volumen;
    double PI = 3.14159;

cout << "Ingrese el radio: ";
cin >> radio;

volumen = (4*PI*pow(radio,3))/3;

cout <<"El volumen es: "<<volumen;
return 0;

}
