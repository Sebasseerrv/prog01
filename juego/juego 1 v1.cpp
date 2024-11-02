#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


void generarNumero(char numero[]) {
    bool usados[10] = {false}; 
    for (int i = 0; i < 4; ) {
        int digito = rand() % 10;
        if (!usados[digito]) {
            usados[digito] = true;
            numero[i++] = '0' + digito;
        }
    }
    numero[4] = '\0';
}

void calcularMuertosYHeridos(const char* respuesta, const char* intento, int& muertos, int& heridos) {
    muertos = 0;
    heridos = 0;
    bool respuestaMarcada[4] = {false};
    bool intentoMarcado[4] = {false};

  
    for (int i = 0; i < 4; i++) {
        if (respuesta[i] == intento[i]) {
            muertos++;
            respuestaMarcada[i] = true;
            intentoMarcado[i] = true;
        }
    }


    for (int i = 0; i < 4; i++) {
        if (!intentoMarcado[i]) {
            for (int j = 0; j < 4; j++) {
                if (!respuestaMarcada[j] && intento[i] == respuesta[j]) {
                    heridos++;
                    respuestaMarcada[j] = true;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    char numeroSecreto[5];
    char intento[5];
    int intentosRestantes = 7;

    generarNumero(numeroSecreto);
    cout << "�Bienvenido! Tienes " << intentosRestantes << " intentos para descubrir el n�mero de 4 d�gitos.\n";

    while (intentosRestantes > 0) {
        cout << "Ingresa tu intento (4 d�gitos): ";
        cin >> intento;

        if (strlen(intento) != 4) {
            cout << "Error: Debes ingresar exactamente 4 d�gitos.\n";
            continue;
        }

        int muertos, heridos;
        calcularMuertosYHeridos(numeroSecreto, intento, muertos, heridos);

        cout << "Muertos: " << muertos << ", Heridos: " << heridos << endl;

        if (muertos == 4) {
            cout << "�Felicidades! Has adivinado el n�mero: " << numeroSecreto << endl;
            return 0;
        }

        intentosRestantes--;
        cout << "Te quedan " << intentosRestantes << " intentos.\n";
    }

    cout << "�Lo siento! Has agotado todos los intentos. El n�mero era: " << numeroSecreto << endl;
    return 0;
}

