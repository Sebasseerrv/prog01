/* programa para imprimir en pantalla todos los numeros primos que termien
en 7 del 100 al 999
elabprado por: sebastian serrano
rev.26/09/2024
*/

#include <iostream>
using namespace std;

int main() {
    int num, div, res;

    // Suponiendo que num se inicializa en algún lugar antes de este código
    cout << "Ingrese un número: ";
    cin >> num;

    div = 2; // Inicializar div en 2
    res = 0; // Inicializar res en 0

    while (div < num) {
        if (num % div == 0) {
            res = 1; // Si num es divisible por div, no es primo
            break;
        }
        div++;
    }

    if (res == 0 && num > 1) {
        cout << num << " es un numero primo." << endl;
    } else {
        cout << num << " no es un numero primo." << endl;
    }

    return 0;
}
