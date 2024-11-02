#include <iostream>
#include <vector>
#include <algorithm> // Incluir la biblioteca para sort
#include <math.h>

using namespace std;

int main() {
    vector<double> N = {-1, -3.3, 100, M_PI, -200, 12};

    // Ordenar el vector en orden ascendente
    sort(N.begin(), N.end());

    // Imprimir el vector ordenado
    for (double num : N) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}