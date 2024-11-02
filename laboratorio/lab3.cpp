/*Programa tutorial inicial para el manejo de las variables tipo cadena de caracteres

autor: Carlos Ferrer

Rev. 1

Nota: Como es un programa Tutorial el mismo se va explicando

*/

#include <iostream>
#include <locale.h> //LIBRERIA PARA TRABAJAR CON LOS CARACTERES ACENTUADOS Y LA LETRA Ñ

using namespace std;

main()
{
    char a;
    int i, j;

    setlocale(LC_ALL, "spanish"); //SETEAR EL LEGUAGE EN ESPAÑOL

    cout <<"Programa elaborado por el Prof. Carlos Ferrer"<<endl;
    cout <<"Rev Cs - Oct 2022 "<<endl;
    cout <<"Manejo de Variables Char (Caracter) y String (Cadena de Caracteres)"<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (1) *****************************"<<endl<<endl;
    cout <<"Las variables tipo Char se caracterizan por que almacenan"<<endl;
    cout <<"un carácter alfanumérico o símbolo especial."<<endl<<endl;
    cout <<"Las variables tipo Char se declaran de la siguiente forma"<<endl;
    cout <<"char var1"<<endl<<endl;
    cout <<"Se le puede asignar un valor directo usando var1='A', el dato"<<endl;
    cout <<"debe ser colocado dentro de comillas simples"<<endl<<endl;
    cout <<endl<<"por ejemplo"<<endl<<endl<<"caracter='a';"<<endl;
    cout <<"caracter='1';"<<endl;
    cout <<"caracter='*';"<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (2) *****************************"<<endl<<endl;	
    cout <<"Si a Las variables tipo Char se le asigna un valor numérico (Sin comillas simples)"<<endl;
    cout <<"la variable tomará el carácter de la tabla ascii de tu computadora"<<endl;
    cout <<"correspondiente a esa posición"<<endl<<endl;
    cout <<"Por ejemplo variable=78"<<endl;
    cout <<"Para este caso el valor almacenado corresponde a la letra N en mayúscula"<<endl<<endl;
    cout <<"este carácter ocupa la posición 78 en la tabla ascii de tu computador"<<endl<<endl;
    cout <<""<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (3) *****************************"<<endl<<endl;	
    cout <<"Procedamos a imprimir los caracteres de la tabla ascii ubicados "<<endl;
    cout <<"en el rango desde el Nro.= 30 hasta el 199 "<<endl<<endl;

    system ("pause");

    for (i=30;i<=199;i=i+1)
    {
        a=i;
        cout <<i<<"="<<a<<" ";	
        if(j==10)
        {
            j=0;
            cout <<endl;
        } 
        j=j+1;
    }

    cout <<endl<<"Nota: Observe como las letras mayúsculas y minúsculas "<<endl;
    cout <<"estan separadas por 32 posiciones (80=P y 112=p) "<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (4) *****************************"<<endl<<endl;	
    cout <<endl<<"Si usted intenta meter en una variable CHAR más de un carácter"<<endl;
    cout <<"el carácter almacenado será el último de la cadena "<<endl;
    cout <<"por ejemplo caracter1='Carlos' el valor almacenado será"<<endl;
    cout <<"el carácter 's'"<<endl<<endl;
    cout <<"Sin embargo el compilador te dará una advertencia (warning) "<<endl;
    cout <<"indicando que la variable tiene overflow "<<endl;
    cout <<"Recuerde que esto no impide que el programa compile "<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (5) *****************************"<<endl<<endl;	
    cout <<endl<<"Si a una variable tipo char (sin comillas) se le aplica una operación"<<endl;
    cout <<"matemática de suma o resta, básicamente lo que hacemos es "<<endl;
    cout <<"cambiar de posición de la tabla ascci"<<endl;
    cout <<"Por ejemplo  "<<endl<<endl;
    cout <<"Char var2= 'B'"<<endl;
    cout <<"var2= var2+32"<<endl<<endl;
    cout <<"Después de esa operación matemática la variable presentará"<<endl;
    cout <<"el siguiente valor var2='b'"<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (6) *****************************"<<endl<<endl;
    cout <<"Las variables tipo string se caracterizan por que almacenan"<<endl;
    cout <<"varios caracteres alfanumérico o símbolo especiales, incluyendo espacios en blanco"<<endl<<endl;
    cout <<"Las variables tipo string se declaran de la siguiente forma"<<endl;
    cout <<"string var2;"<<endl<<endl;

    a=34;

    cout <<"Se le puede asignar un valor directo de la siguiente manera: var2="<<a<<"Caracas"<<a<<"; el dato"<<endl;
    cout <<"debe ser colocado dentro de comillas dobles"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (7) *****************************"<<endl<<endl;	
    cout <<"Una variable string se recomienda sea declarada dentro del "<<endl;
    cout <<"programa principal Main o dentro de las funciones."<<endl<<endl;
    cout <<"No es recomendable declararla como una variable Global."<<endl<<endl;
    cout <<"(Afuera del Main y de las funciones)"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (8) *****************************"<<endl<<endl;	
    cout <<"El compilador de Dev C++ entiende a una variable string"<<endl;
    cout <<"como un arreglo tipo Char[n] donde n será la cantidad"<<endl;
    cout <<"de letras del string menos 1, dado que la primera posición"<<endl;
    cout <<"se entiende como la posición 0."<<endl<<endl;
    cout <<"Veamos un ejemplo:"<<endl;
    cout <<"string cadena1"<<endl;
    cout <<"cadena1"<<a<<"Carlos"<<a<<endl<<endl;
    cout <<"cadena1[0]='C'"<<endl;
    cout <<"cadena1[1]='a'"<<endl;
    cout <<"cadena1[2]='r'"<<endl;
    cout <<"cadena1[3]='l'"<<endl;
    cout <<"cadena1[4]='o'"<<endl;
    cout <<"cadena1[5]='s'"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (9) *****************************"<<endl<<endl;	
    cout <<"Dos variables tipo string se pueden concatenar en otra variable"<<endl;
    cout <<"usando el operador (+)"<<endl;
    cout <<"veamos el ejemplo:"<<endl<<endl;
    cout <<"string var1,var2,var3;"<<endl;
    cout <<"var1="<<a<<"Carlos"<<a<<endl;
    cout <<"var2="<<a<<"Ferrer"<<a<<endl;
    cout <<"var3="<<"var1 +"<<a<<" "<<a<<"+ var2;"<<endl;
    cout <<"El valor final de Var3 corresponderá"<<endl;
    cout <<"Var3= "<<a<<"Carlos Ferrer"<<a<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (10) *****************************"<<endl<<endl;		
    cout <<"Si usted intenta leer una variable string"<<endl;
    cout <<"desde la consola usando la instrucción cin"<<endl;
    cout <<"el dato se almacenara hasta el primer espacio en blanco"<<endl<<endl;
    cout <<"Por ejemplo:"<<endl<<endl;

    a='"';

    cout <<"string var2;"<<endl;

    a='"';

    cout <<"cout <<"<<a<<"ingrese nombre y apellido"<<a<<"<<endl;"<<endl;
    cout <<"cin >>var2;"<<endl<<endl;
    cout <<"Si el usuario ingresa "<<a<<"Pedro Guerra"<<a<<endl;
    cout <<"El único dato que se almacenará en la variable var2 será= "<<a<<"Pedro"<<a<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (10) Continuación *****************************"<<endl<<endl;		
    cout <<"Para poder almacenar la cadena de caracteres completa"<<endl;
    cout <<"usted debe usar una una instrucción de la biblioteca "<<a<<"iostream"<<a<<endl;
    cout <<"que permite leer líneas completa: getline()"<<endl;
    cout <<"dentro de los paréntesis usted indicará que ejecutará la función"<<endl;
    cout <<"Console input y la variable que recibirá el dato: getline(cin,var2);"<<endl;
    cout <<"modifiquemos el código de la forma correcta"<<endl<<endl;
    cout <<"string var2;"<<endl;

    a='"';

    cout <<"cout <<"<<a<<"ingrese nombre y apellido"<<a<<"<<endl;"<<endl;
    cout <<"cin.ignore(); /*Se se utiliza para ignorar lo que hay en el buffer o un dato anterior"<<endl;   
    cout <<"                Normalmente el primer getline no requiere el comando ignorar*/"<<endl; 
    cout <<"getline(cin,var2);"<<endl<<endl;
    cout <<"Si el usuario ingresa "<<a<<"Pedro Guerra"<<a<<endl;
    cout <<"El dato que se almacenará en la variable var2 será= "<<a<<"Pedro Guerra"<<a<<endl;
    cout <<"(Incluyendo el espacio en blanco como un carácter)"<<a<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (11)  *****************************"<<endl<<endl;		
    cout <<"Nosotros podemos extraer una cadena de caracteres a partir de otra"<<endl;
    cout <<"cadena de caracteres usando el parámetro "<<a<<"substr()"<<a<<endl;
    cout <<"este parámetro actúa sobre el dato a extraer"<<endl;
    cout <<"dentro de los paréntesis se indica en principio la posición del carácter"<<endl;
    cout <<"a partir del cual se ejecutará la extracción, veamos un ejemplo:"<<endl<<endl;
    cout <<"string var1,var2;"<<endl;

    a='"';

    cout <<"var1="<<a<<"123456 89ABCD"<<a<<";"<<endl;
    cout <<"var2=var1.substr(4);"<<endl<<endl;
    cout <<"En var2 se guardará ="<<endl;
    cout <<a<<"56 89ABCD"<<a<<endl<<endl;
    cout <<"Recuerde que las cadenas de caracteres arrancan"<<endl;
    cout <<"en la posición Cero (0), por eso el carácter de la posición 4 es el cinco (5)"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (11) Continuación *****************************"<<endl<<endl;		
    cout <<"Al parámetro substr se le puede agregar en los paréntesis "<<endl;
    cout <<"un segundo elemento que correspondería a la cantidad de"<<endl;
    cout <<"caracteres que vas a extraer"<<endl<<endl;
    cout <<"veamos un ejemplo:"<<endl<<endl;
    cout <<"string var1,var2;"<<endl;

    a='"';

    cout <<"var1="<<a<<"Profesión= Ingeniero Industrial"<<a<<";"<<endl;
    cout <<"var2=var1.substr(11,9);"<<endl<<endl;
    cout <<"En var2 se guardará ="<<endl;
    cout <<a<<"Ingeniero"<<a<<endl<<endl;
    cout <<"nota: recuerde la posición de la frase arranca en (0) cero"<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (12)  *****************************"<<endl<<endl;		
    cout <<"El parámetro "<<a<<"size()"<<a<<" retorna la cantidad de caracteres"<<endl;
    cout <<"de una cadena de caracteres"<<endl;
    cout <<"veamos un ejemplo:"<<endl<<endl;
    cout <<"string var1;"<<endl;
    cout <<"int cantidad;"<<endl;

    a='"';

    cout <<"var1="<<a<<"Esto es una Prueba"<<a<<";"<<endl;
    cout <<"cantidad=var1.size();"<<endl<<endl;
    cout <<"En cantidad se guardará = 18"<<endl<<endl;
    cout <<"Recuerde que las cadenas de caracteres arrancan"<<endl;
    cout <<"en la posición Cero (0), como esta cadena tiene 18 caracteres"<<endl;
    cout <<"terminará en la posición dieciocho (17)"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (13)  *****************************"<<endl<<endl;		
    cout <<"El parámetro "<<a<<"find()"<<a<<" retorna la posición en la que aparece"<<endl;
    cout <<"una cadena de caracteres dentro de otra"<<endl;
    cout <<"veamos un ejemplo:"<<endl<<endl;
    cout <<"string var1;"<<endl;
    cout <<"int Pos;"<<endl;

    a='"';

    cout <<"var1="<<a<<"Esto es una Prueba"<<a<<";"<<endl;
    cout <<"Pos=var1.find("<<a<<"Pru"<<a<<");"<<endl<<endl;
    cout <<"En Pos se guardará = 12"<<endl<<endl;
    cout <<"Este valor corresponde a la posición donde comienza la cadena"<<endl;
    cout <<"de caracteres "<<a<<"Pru"<<a<<" dentro de var1"<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (13)  Continuación *****************************"<<endl<<endl;		
    cout <<"veamos otro ejemplo:"<<endl<<endl;
    cout <<"string var1,var2;"<<endl;
    cout <<"int Pos;"<<endl;

    a='"';

    cout <<"var1="<<a<<"Esto es una Prueba"<<a<<";"<<endl;
    cout <<"var2="<<a<<" e"<<a<<";"<<endl;
    cout <<"Pos=var1.find(var2);"<<endl<<endl;
    cout <<"En Pos se guardará = 5"<<endl<<endl;
    cout <<"Este valor corresponde a la posición donde comienza la cadena"<<endl;
    cout <<"de caracteres "<<a<<" e"<<a<<" dentro de var1"<<endl<<endl;
    cout <<"Recuerde los espacios en blanco son caracteres existentes"<<endl<<endl;

    system ("pause");
    system ("cls");

    cout <<"************************** (13) Continuación *****************************"<<endl<<endl;		
    cout <<"El parámetro find() tambien puede retornar la posición en la que aparece"<<endl;
    cout <<"una cadena de caracteres a partir de una posición específica"<<endl;
    cout <<"veamos un ejemplo:"<<endl<<endl;
    cout <<"string var1;"<<endl;
    cout <<"int Pos;"<<endl;

    a='"';

    cout <<"var1="<<a<<"Esto es una Prueba especial"<<a<<";"<<endl;
    cout <<"Pos=var1.find("<<a<<"es"<<a<<";10);"<<endl<<endl;
    cout <<"En Pos se guardará = 19"<<endl<<endl;
    cout <<"Este valor corresponde a la posición donde comienza la cadena"<<endl;
    cout <<"de caracteres "<<a<<"es"<<a<<" dentro de var1 después de la decima posición"<<endl<<endl;
    cout <<"Nota: Observen como la primera cadena "<<a<<"es"<<a<<" se ignora porque esta antes de la posición 10"<<endl<<endl;

    system ("pause");
    system("cls");

    cout <<"************************** (14)  Actividad del estudiante *****************************"<<endl<<endl;		
    cout <<"Elabore un programa que permita capturar desde la consola"<<endl;
    cout <<"una cadena de caracteres de 5 palabras en una variable string."<<endl<<endl;
    cout <<"Este programa debera sustituir todas las vocales de las 5 palabras por asteriscos y después"<<endl;
    cout <<"invertir el sentido de cada palabra"<<endl<<endl;
    cout <<"Por ejemplo:"<<endl<<endl;
    cout <<"Ingrese frase de tres palabras = La Florencia Caracas"<<endl<<endl;
    cout <<"Resultado = *L **cn*r*lF s*c*r*C"<<endl<<endl;
    cout <<"ÉXITO!!!!"<<endl<<endl;

    system ("pause");
    system ("cls");
}