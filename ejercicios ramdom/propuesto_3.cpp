/*
Realice un programa que diga un numero que termine en 9, su raiz sea entera y termine en 7, que a su ves sea divisible entre 3
y ese resultado sea primo en un rango desde 5000 hasta que consiga los primeros
20 numeros
*/

#include <iostream>
#include <cmath>
using namespace std;

// Función que verifica si un número es primo
bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // si el numero es divisible entre 2
    for (int i = 3; i <= sqrt(n); i += 2) { // si el numero es divisible entre 3
        if (n % i == 0) return false; // si el numero es divisible entre i
    }
    return true;
}

int main() {
    int n = 5000;
    int contador = 0;
    while (contador < 20) { // 20 primeros numeros
        if (n % 10 == 9) { // si el numero termina en 9
            int raiz = sqrt(n);
            if (raiz % 10 == 7) { // si la raiz termina en 7
                if (n % 3 == 0) {
                    if (es_primo(n / 3)) { // si el resultado de la division entre 3 es primo
                        cout << n << " " << n / 3 << " " << raiz << endl;
                        contador++;
                    }
                }
            }
        }
        n++;
    }
    return 0;
}