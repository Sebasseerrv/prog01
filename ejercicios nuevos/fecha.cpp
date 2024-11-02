/*Crear un programa que determine el día de la semana (lunes, martes, miércoles, jueves, viernes,) que

corresponde a cualquier fecha entre el 01 de enero de 1968

y el 31 de dic de 2024*/

#include <iostream>
#include <cmath>

using namespace std;

#include <iostream>
#include <cmath>

using namespace std;
 // se puede usar la formula de Zeller para calcular el dia de la semana
int calcularDiaSemana(int dia, int mes, int anio) {
    if (mes == 1 || mes == 2) {
        mes += 12;
        anio -= 1;
    }
    int K = anio % 100;
    int J = anio / 100;
    int h = (dia + (13 * (mes + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return h;
}
//usar un switch y un string para obtener el nombre del dia segun el numero dela formula zeller
string obtenerNombreDia(int dia_semana) {
    switch (dia_semana) {
        case 0: return "Sabado";
        case 1: return "Domingo";
        case 2: return "Lunes";
        case 3: return "Martes";
        case 4: return "Miercoles";
        case 5: return "Jueves";
        case 6: return "Viernes";
        default: return "Error";
    }
}
// se pide la fecha y se imprime el dia de la semana
int main() {
    int dia, mes, anio, dia_semana;

    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    if (anio < 1968 || anio > 2024) {
        cout << "Fecha fuera del rango permitido (1968-2024)." << endl;
        return 1;
    }

    dia_semana = calcularDiaSemana(dia, mes, anio);
    string nombre_dia = obtenerNombreDia(dia_semana);

    cout << "El dia de la semana es: " << nombre_dia << endl;

    return 0;
}