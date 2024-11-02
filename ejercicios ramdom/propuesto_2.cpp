
/*
Elabore un programa que presente en pantalla los primeros veinte 20 números que:

a.- Que finalicen en uno (1).

b.- Que sean divisibles exactamente entre veintiuno (21).

c.- Que el resultado de su división entre veintiuno (21) al sacarle la raíz cuadrada de un numero entero que termine en uno (1).

El rango a revisar es desde 50000 hasta que consiga los veinte (20) números.

En la pantalla deberá presentarse el número, su división entre veintiuno (21) y la raíz cuadrada de ese resultado que termina en uno (1):
*/


#include <iostream>
#include <cmath>
using namespace std;

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int contador = 0;
    for (int i = 50000; contador < 20; i++) {
        if (i % 21 == 0 && i % 10 == 1) {
            cout << i << " " << i / 21 << " " << sqrt(i / 21) << endl;
            contador++;
        }
    }
    return 0;
}