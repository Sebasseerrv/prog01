 // imprimir los numeros primos del 1 al 100

 #include <iostream>

 using namespace std;

 int i =0;
 int j =0;
//creamos un wile para saber si es primo
    int main(){
        for (i = 1; i <= 100; i++){//creamos un for para saber si es primo
            int contador = 0;//creamos un contador
            for (j = 1; j <= i; j++){//creamos un for para saber si es primo
                if (i % j == 0){//si el residuo de la division es 0
                    contador++;
                }
            }
            if (contador == 2){
                cout << i << endl;
            }
        }
        return 0;
    }