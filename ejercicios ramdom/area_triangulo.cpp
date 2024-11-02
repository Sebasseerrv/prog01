#include <iostream>

int main() {
    //creando variables
    double base, altura, area;
// dandole valores a las variables
    std::cout << "Ingrese la base del triangulo: ";
    std::cin >> base;

    std::cout << "Ingrese la altura del triangulo: ";
    std::cin >> altura;
// calculo para tener el area
    area = 0.5 * base * altura;
// imprimir el resultado
    std::cout << "El area del triangulo es: " << area << std::endl;

    return 0;
}