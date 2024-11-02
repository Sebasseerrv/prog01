/*
Escribe una función que reciba dos palabras (String) y retorne
verdadero o falso (Bool) según sean o no anagramas.
Un Anagrama consiste en formar una palabra reordenando TODAS
las letras de otra palabra inicial.
NO hace falta comprobar que ambas palabras existan.
Dos palabras exactamente iguales no son anagrama.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool anagrama(string palabra1, string palabra2) {
    // Verificar que las palabras no sean exactamente iguales
    if (palabra1 == palabra2) return false;

    // Verificar que las palabras tengan la misma longitud
    if (palabra1.length() != palabra2.length()) return false;

    // Ordenar ambas palabras
    sort(palabra1.begin(), palabra1.end());
    sort(palabra2.begin(), palabra2.end());

    // Comparar las palabras ordenadas
    return palabra1 == palabra2;
}

int main() {
    string palabra1, palabra2;
    cout << "Ingrese la primera palabra: ";
    cin >> palabra1;
    cout << "Ingrese la segunda palabra: ";
    cin >> palabra2;

    if (anagrama(palabra1, palabra2)) {
        cout << "Las palabras son anagramas." << endl;
    } else {
        cout << "Las palabras no son anagramas." << endl;
    }

    return 0;
}