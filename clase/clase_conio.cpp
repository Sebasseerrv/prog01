/*clase en la que se presenta kbhit() y getch()

Las funciones _kbhit() y _getch() son parte de la biblioteca conio.h y se utilizan para la entrada de teclado en aplicaciones de consola en C++.

_kbhit():
- Propósito: Detectar si hay una tecla presionada.
- Funcionamiento: _kbhit() devuelve un valor distinto de cero si una tecla ha sido presionada y está en el buffer de entrada de la consola. Si no hay ninguna tecla presionada, devuelve cero.
- Uso: Es útil en situaciones donde se necesita realizar una acción condicionalmente basada en la entrada del usuario sin detener la ejecución del programa. En el código proporcionado, se usa dentro de un bucle para verificar constantemente si el usuario ha presionado una tecla mientras el contador sigue funcionando.

_getch():
- Propósito: Leer un carácter directamente del teclado sin mostrarlo en la consola.
- Funcionamiento: _getch() lee un carácter del teclado y lo devuelve, sin que el carácter se muestre en la consola. Esto es útil para contraseñas o entradas donde no se desea que los caracteres aparezcan en pantalla.
- Uso: En el código proporcionado, _getch() se utiliza para capturar la entrada del usuario carácter por carácter para construir la clave ingresada (entered_password). Cada vez que el usuario presiona una tecla, _getch() la captura y la agrega a la cadena de la clave ingresada.

Ejemplo en el código:
En el código proporcionado, _kbhit() y _getch() se utilizan para implementar una función que espera a que el usuario ingrese una contraseña para detener un contador de cuenta regresiva.

- El bucle while (!stop) mantiene el programa ejecutándose hasta que se ingrese la contraseña correcta.
- Dentro del bucle, _kbhit() verifica continuamente si una tecla ha sido presionada.
- Si una tecla ha sido presionada, _getch() lee la tecla y la agrega a entered_password.
- Si la tecla presionada es la tecla Enter (\r), se verifica si la contraseña ingresada coincide con correct_password. Si coincide, se detiene el contador.

De esta manera, _kbhit() y _getch() permiten que el programa responda a la entrada del usuario sin detener el flujo de ejecución del contador.
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void countdown() {
    int seconds = 60;
    while (seconds > 0) {
        cout << "\rTiempo restante: " << seconds << " segundos" << flush;
        Sleep(1000);
        seconds--;
    }
    cout << "\n¡Tiempo agotado!" << endl;
}

int main() {
    const string correct_password = "1301";
    string entered_password = "";
    char ch;
    bool stop = false;

    thread countdown_thread(countdown);

    cout << "Introduce la clave para detener el contador: ";

    while (!stop) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') { // Enter key
                if (entered_password == correct_password) {
                    stop = true;
                    cout << "\nClave correcta. ¡El contador se ha detenido!" << endl;
                } else {
                    cout << "\nClave incorrecta. Intenta de nuevo: ";
                    entered_password.clear();
                }
            } else {
                entered_password += ch;
                cout << '*';
            }
        }
    }

    countdown_thread.detach();
    return 0;
}

