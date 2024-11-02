#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>

using namespace std;

string replaceVowelsAndReverse(const string& word) {
    string modifiedWord = word;
    for (char& c : modifiedWord) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            c = '*';
        }
    }
    reverse(modifiedWord.begin(), modifiedWord.end());
    return modifiedWord;
}

// Función principal del programa
int main() {
    // Configura la localización para admitir caracteres especiales
    setlocale(LC_ALL, "");
 setlocale(LC_ALL, "spanish");
    string input;
    // Solicita al usuario que ingrese una frase de cinco palabras
    cout << "Ingrese frase de cinco palabras: ";
    // Lee la línea completa de entrada del usuario
    getline(cin, input);

    string word;
    string result;
    size_t start = 0, end = 0;

    // Bucle para procesar cada palabra en la frase
    while ((end = input.find(' ', start)) != string::npos) {
        // Extrae una palabra desde la posición 'start' hasta 'end'
        word = input.substr(start, end - start);
        // Reemplaza las vocales y revierte la palabra, luego la añade al resultado
        result += replaceVowelsAndReverse(word) + " ";
        // Actualiza la posición de inicio para la siguiente palabra
        start = end + 1;
    }
    // Procesa la última palabra (o la única palabra si no hay espacios)
    word = input.substr(start);
    result += replaceVowelsAndReverse(word);

    // Imprime el resultado final
    cout << "Resultado = " << result << endl;

    return 0;
}