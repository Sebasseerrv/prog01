#include <iostream>

using namespace std;



int main()

{

int num=100,	div=2,aux;

double aux2;

repetir:

// calculamos el modulo de div

aux=num%div; 

//Preguntamos si se xxxxxxxxxxx	

if (aux==0)

	{

	if(div==num) //Verificamos que sea igual que el nuero

		{

		aux2=num;

		aux2=aux2/10;

		aux=num/10

		aux2=aux2-aux;

		if(aux2>0.69 and aux2<0.71) // verificamos que la division del num este entre 0.69 y 0.72

			{

			cout <<num<<" ";	

			}

		}

		num=num+1; // Si hay división  exacta me muevo al siguiente xxxxx

		div=2;

	}

	else // si no es división xxxx paso al siguiente xxxxx

	{

	div=div+1;

	}



if(num<1000)

	{

	goto repetir;	

	}	
return 0;
}

