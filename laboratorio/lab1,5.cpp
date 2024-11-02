#include <iostream>

using namespace std;

int main() {
    int num = 100, div = 2, aux; // Inicializamos num en 100, div en 2 y declaramos aux
    double aux2; 

    repetir: 

    aux = num % div; // Calculamos el resto de num dividido por div

    if (aux == 0) { // Verificamos si num es divisible por div sin residuo
        if (div == num) { // Verificamos que el divisor sea igual al número
            aux2 = num; // Asignamos el valor de num a aux2
            aux2 = aux2 / 10; // Dividimos aux2 por 10
            aux = num / 10; // Dividimos num por 10 y asignamos el resultado a aux
            aux2 = aux2 - aux; // Restamos aux de aux2 para obtener la parte decimal

            if (aux2 > 0.69 and aux2 < 0.71) { // Verificamos que la parte decimal esté entre 0.69 y 0.71
                cout << num << " "; // Imprimimos num si cumple con la condición
        }

        num = num + 1; // Si hay división exacta, incrementamos num en 1
        div = 2; 
    } else { 
        div = div + 1; 
    }

    if (num < 1000) { // Verificamos si num es menor que 1000
        goto repetir; // Si es menor, repetimos el bucle
    }

    return 0; 
}