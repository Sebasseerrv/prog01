/*
  Escribe un programa que imprima los 50 primeros números de la sucesión
 de Fibonacci empezando en 0.
- La serie Fibonacci se compone por una sucesión de números en
   la que el siguiente siempre es la suma de los dos anteriores.
   0, 1, 1, 2, 3, 5, 8, 13...
 */


#include <iostream>
using namespace std;

// Función para verificar si un año es bisiesto
bool esBisiesto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Función para calcular los días desde el inicio del año 2000 hasta una fecha dada
int diasDesdeInicio(int dia, int mes, int ano) {
    int dias = 0; // Inicializa el contador de días
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Días en cada mes

    // Sumar días de los años completos
    for (int i = 2000; i < ano; ++i) {
        dias += esBisiesto(i) ? 366 : 365; // Añade 366 días si es bisiesto, 365 si no lo es
    }

    // Sumar días de los meses completos del año actual
    for (int i = 0; i < mes - 1; ++i) {
        dias += diasPorMes[i]; // Añade los días de cada mes completo
        if (i == 1 && esBisiesto(ano)) { // Si es febrero en un año bisiesto
            dias += 1; // Añade un día extra
        }
    }

    // Sumar días del mes actual
    dias += dia - 1; // Añade los días del mes actual

    return dias;
}

// Función para calcular el día de la semana
string calcularDiaSemana(int dia, int mes, int ano) {
    int dias = diasDesdeInicio(dia, mes, ano);
    int diaSemana = (dias + 6) % 7; // 1 de enero de 2000 fue sábado, ajustamos con +6
    string diasSemana[] = {"Sabado", "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    return diasSemana[diaSemana];
}

int main() {
    int anio;
    cout << "Ingrese un año entre 2024 y 2099: ";
    cin >> anio;

    if (anio < 2024 || anio > 2099) {
        cout << "Año fuera del rango permitido." << endl;
        return 1;
    }

    // Lista de feriados
    int dias[] = {1, 19, 1, 24, 5, 24, 12, 24, 25, 31};
    int meses[] = {1, 4, 5, 7, 7, 6, 10, 12, 12, 12};
    string nombresFeriados[] = {"1 de Enero", "19 de Abril", "1 de Mayo", "24 de Julio", "5 de Julio", "24 de Junio", "12 de Octubre", "24 de Diciembre", "25 de Diciembre", "31 de Diciembre"};

    cout << "Dias feriados y sus dias de la semana en el año " << anio << ":" << endl;
    for (int i = 0; i < 10; i++) {
        string diaSemana = calcularDiaSemana(dias[i], meses[i], anio);
        cout << nombresFeriados[i] << ": " << diaSemana << endl;
    }

    return 0;
}