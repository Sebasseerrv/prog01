// Programa que presente los primeros 20 numeros primos que al sacarle la raiz cuadrada el resultado termine en 7.
// y que solo sean numeros enteros.
// en la pantalla se deben presentar el numero y su raiz 
#include <cmath> // Incluye la biblioteca cmath para usar la función sqrt
#include <iostream> // Incluye la biblioteca iostream para usar cout

using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) return false; // Los números menores o iguales a 1 no son primos
    for (int i = 2; i <= sqrt(num); i++) { // Itera desde 2 hasta la raíz cuadrada del número
        if (num % i == 0) return false; // Si el número es divisible por i, no es primo
    }
    return true; // Si no se encontró ningún divisor, el número es primo
}

int main() {
    int i = 0; // Contador para los primeros 20 números que cumplen la condición
    int j = 100000; // Inicializar j en 100000

    while (i < 20) { // Mientras i sea menor a 20
        j++; // Incrementa j
        if (esPrimo(j)) { // Verificar si j es un número primo
            int raiz_entera = static_cast<int>(sqrt(j)); // Calcular la parte entera de la raíz cuadrada de j
            if (raiz_entera * raiz_entera == j && raiz_entera % 10 == 7) { // Verificar si la raíz cuadrada es un número entero y termina en 7
                cout << "Número: " << j << ", Raíz: " << raiz_entera << endl; // Imprime el número y su raíz cuadrada
                i++; // Incrementa el contador i
            }
        }
    }
    return 0; // Termina el programa
}