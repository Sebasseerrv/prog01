/*
 
Crea una única función (importante que sólo sea una) que sea capaz
de calcular y retornar el área de un polígono.
La función recibirá por parámetro sólo UN polígono a la vez.
Los polígonos soportados serán Triángulo, Cuadrado y Rectángulo.
Imprime el cálculo del área de un polígono de cada tipo.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Función que calcula el área de un triángulo
double area_triangulo(double base, double altura) {
    return (base * altura) / 2;
}

// Función que calcula el área de un cuadrado
double area_cuadrado(double lado) {
    return lado * lado;
}

// Función que calcula el área de un rectángulo
double area_rectangulo(double base, double altura) {
    return base * altura;
}

// Función que calcula el área de un polígono
double area_poligono(string poligono, double a, double b) {
    if (poligono == "triangulo") {
        return area_triangulo(a, b);
    } else if (poligono == "cuadrado") {
        return area_cuadrado(a);
    } else if (poligono == "rectangulo") {
        return area_rectangulo(a, b);
    } else {
        return -1;
    }
}

int main() {
    cout << "El area de un triangulo de base 5 y altura 3 es: " << area_poligono("triangulo", 5, 3) << endl;
    cout << "El area de un cuadrado de lado 4 es: " << area_poligono("cuadrado", 4, 0) << endl;
    cout << "El area de un rectangulo de base 6 y altura 2 es: " << area_poligono("rectangulo", 6, 2) << endl;
    return 0;
}
