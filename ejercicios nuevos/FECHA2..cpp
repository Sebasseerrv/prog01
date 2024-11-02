#include <iostream>
#include <cmath>

using namespace std;
 // se puede usar la formula de Zeller para calcular el dia de la semana
 int calcularDiaSemana(int dia, int mes,int anio){
        if (mes == 1 || mes == 2) {
            mes += 12;
            anio -= 1;
        }
        int K = anio % 100;
        int J = anio / 100;
        int h = (dia + (13 * (mes + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
        return h;
 }

 string ObtenerNombreDia(int dia_semana){
    switch (dia_semana)
    {
    case 0: return "Sabado";
    case 1: return "Domingo";
    case 2: return "Lunes";
    case 3: return "Martes";
    case 4: return "Miercoles";
    case 5: return "Jueves";
    case 6: return "Viernes";
    default: return "Error";
        break;
    }

 }
 int main(){
    int dia, mes, anio, dia_semana;

    cout <<"ingrese dia de la semana:";
    cin >> dia;
    cout <<"ingrese mes de la semana:";
    cin >> mes;
    cout <<"ingrese anio de la semana:";
    cin >> anio;

    if (anio<1968 || anio>2024){
        cout << "fecha fuera del rango permitido (1968-2024)." << endl;
        return 1;
    }
    dia_semana = calcularDiaSemana(dia, mes, anio);
    string nombre_dia = ObtenerNombreDia(dia_semana);

    cout << "El dia de la semana es: " << nombre_dia << endl;

    return 0;
 }