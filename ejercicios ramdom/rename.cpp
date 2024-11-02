/*
  Escribe un programa que imprima los 50 primeros números de la sucesión
  de Fibonacci empezando en 0.
  - La serie Fibonacci se compone por una sucesión de números en
    la que el siguiente siempre es la suma de los dos anteriores.
    0, 1, 1, 2, 3, 5, 8, 13...
 */

#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < 50; i++){ // 50 primeros numeros de la sucesion de fibonacci
        cout << c << endl;
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}