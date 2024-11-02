/*
Escribe un programa que muestre por consola los
números de 1 a 100 (ambos incluidos y con un salto de línea entre
cada impresión), sustituyendo los siguientes:
Múltiplos de 3 por la palabra "fizz".
Múltiplos de 5 por la palabra "buzz".
Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) { 
        if (i % 3 == 0 && i % 5 == 0) { // si el numero es divisible entre 3 y 5
            cout << "fizzbuzz" << endl;
        } else if (i % 3 == 0) {// si el numero es divisible entre 3
            cout << "fizz" << endl;
        } else if (i % 5 == 0) {// si el numero es divisible entre 5
            cout << "buzz" << endl;
        } else { // si no es divisible entre 3 ni 5
            cout << i << endl;
        }
    }
    return 0;
}