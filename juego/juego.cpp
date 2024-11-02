/*
este es un juego llamado el muerto y el herido se trata de lo siguiente, osn dos jugadores el codificador (al azar) y el decodificador (el que adivina)
Uno piensa un número de cuatro cifras que el otro debe adivinar en el mismo orden en que el primero lo ha memorizado. 
Cuando el encargado de acertarlo dice el número que se le ocurre, el primero le indica «cuántos heridos y muertos» tiene. 
Muerto significa que ha acertado la cifra en el orden correspondiente y herido que lo ha hecho pero no el lugar en que debe figurar.
*/

#include <iostream>
#include <ctime>
#include <windows.h> // For Beep function

using namespace std;

const int COSTO_TIRADA = 200;
const int RECOMPENSA_HERIDO = 20;
const int RECOMPENSA_MUERTO = 100;

int generarNumero() {
    // Generar un número de cuatro cifras
    return rand() % 9000 + 1000;
}

void compararNumeros(int numeroGenerado, int numeroAdivinado, int &muertos, int &heridos) {
    string strGenerado = to_string(numeroGenerado);
    string strAdivinado = to_string(numeroAdivinado);
    muertos = 0;
    heridos = 0;

    // Contar "muertos"
    for (int i = 0; i < 4; i++) {
        if (strGenerado[i] == strAdivinado[i]) {
            muertos++;
        }
    }

    // Contar "heridos"
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && strGenerado[i] == strAdivinado[j]) {
                heridos++;
            }
        }
    }
}

int main() {
    srand(time(0)); // Inicializar el generador de números aleatorios
    int numeroGenerado = generarNumero();
    int numeroAdivinado;
    int muertos, heridos;
    int dinero = 1600;

    cout << "Bienvenido al juego 'El muerto y el herido'!" << endl;
    cout << "Intenta adivinar el numero de cuatro cifras." << endl;

    do {
        cout << "Ingresa tu adivinanza: ";
        cin >> numeroAdivinado;

        compararNumeros(numeroGenerado, numeroAdivinado, muertos, heridos);

        dinero -= COSTO_TIRADA;
        dinero += (muertos * RECOMPENSA_MUERTO) + (heridos * RECOMPENSA_HERIDO);

        for (int i = 0; i < muertos; ++i) {
            Beep(1000, 500); // Beep sound for muertos
        }

        for (int i = 0; i < heridos; ++i) {
            Beep(500, 500); // Beep sound for heridos
        }

        if (muertos == 4) {
            cout << "¡Felicidades! Has adivinado el número correctamente." << endl;
            break;
        } else {
            cout << "Muertos: " << muertos << ", Heridos: " << heridos << endl;
            cout << "Dinero restante: $" << dinero << endl;
        }

        if (dinero < COSTO_TIRADA) {
            cout << "Lo siento, has perdido. El número era: " << numeroGenerado << endl;
            break;
        }
    } while (muertos != 4);

    system("pause");
    return 0;
}