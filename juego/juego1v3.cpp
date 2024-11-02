#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <conio.h> // Para usar _getch()
#include <windows.h> // Para usar Beep() y SetConsoleOutputCP

using namespace std;

const int COSTO_TIRADA = 200;
const int RECOMPENSA_HERIDO = 20;
const int RECOMPENSA_MUERTO = 100;
const int VIDAS_INICIALES = 10;
const string ARCHIVO_PARTIDA = "partida_guardada.txt";

// Declaraciones de funciones
void generarNumero(char numero[]);
void calcularMuertosYHeridos(const char* respuesta, const char* intento, int& muertos, int& heridos);
bool verificarUsuario(const string& nombreUsuario);
void agregarUsuario(const string& nombreUsuario);
void mostrarReglas();
void mostrarMenu();
void guardarPartida(const char* numeroGenerado, int dinero);
bool cargarPartida(char* numeroGenerado, int& dinero);
void jugarContraMaquina();
void jugarDosJugadores();
bool validarEntrada(const string& entrada);
bool validarOpcionMenu(const string& entrada);

// Función para generar un número de cuatro cifras único
void generarNumero(char numero[]) {
    bool usados[10] = {false}; 
    for (int i = 0; i < 4; ) {
        int digito = rand() % 10;
        if (!usados[digito]) {
            usados[digito] = true;
            numero[i++] = '0' + digito;
        }
    }
    numero[4] = '\0';
}

// Función para calcular muertos y heridos
void calcularMuertosYHeridos(const char* respuesta, const char* intento, int& muertos, int& heridos) {
    muertos = 0;
    heridos = 0;
    bool respuestaMarcada[4] = {false};
    bool intentoMarcado[4] = {false};

    // Contar muertos
    for (int i = 0; i < 4; i++) {
        if (respuesta[i] == intento[i]) {
            muertos++;
            respuestaMarcada[i] = true;
            intentoMarcado[i] = true;
        }
    }

    // Contar heridos
    for (int i = 0; i < 4; i++) {
        if (!respuestaMarcada[i]) {
            for (int j = 0; j < 4; j++) {
                if (!intentoMarcado[j] && respuesta[i] == intento[j]) {
                    heridos++;
                    respuestaMarcada[i] = true;
                    intentoMarcado[j] = true;
                    break;
                }
            }
        }
    }
}

// Función para verificar si el usuario ya existe en el archivo
bool verificarUsuario(const string& nombreUsuario) {
    ifstream archivo("usuarios.txt");
    string linea;
    while (getline(archivo, linea)) {
        if (linea == nombreUsuario) {
            return true;
        }
    }
    return false;
}

// Función para agregar un nuevo usuario al archivo
void agregarUsuario(const string& nombreUsuario) {
    ofstream archivo("usuarios.txt", ios::app);
    archivo << nombreUsuario << endl;
}

// Función para mostrar las reglas del juego
void mostrarReglas() {
    system("cls");
    cout << "Reglas del Juego:\n";
    cout << "1. Cada jugador debe adivinar un número de cuatro cifras.\n";
    cout << "2. Un 'muerto' significa que un dígito está en la posición correcta.\n";
    cout << "3. Un 'herido' significa que un dígito está en el número pero en la posición incorrecta.\n";
    cout << "4. En el modo de un jugador, cada intento cuesta 200 unidades de dinero.\n";
    cout << "5. En el modo de dos jugadores, cada intento cuesta una vida.\n";
    cout << "6. El primer jugador en adivinar el número del oponente gana.\n";
    cout << "7. Si te quedas sin dinero o vidas, pierdes.\n";
    cout << "\nPresione cualquier tecla para volver al menú principal...";
    _getch();
}

// Función para mostrar el menú de inicio
void mostrarMenu() {
    string opcion;
    do {
        system("cls");
        Beep(523, 500); // Beep similar al sonido de Mario Bros
        cout << "Bienvenido al juego 'El muerto y el herido'!" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Jugar Modo 1 (Dos jugadores)" << endl;
        cout << "2. Jugar Modo 2 (Contra la máquina)" << endl;
        cout << "3. Conocer las reglas del juego" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        if (!validarOpcionMenu(opcion)) {
            cout << "Opción no válida. Intente de nuevo." << endl;
            system("pause");
            continue;
        }

        switch(stoi(opcion)) {
            case 1:
                jugarDosJugadores();
                break;
            case 2:
                jugarContraMaquina();
                break;
            case 3:
                mostrarReglas();
                break;
            case 4:
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while(opcion != "4");
}

// Función para guardar el estado del juego
void guardarPartida(const char* numeroGenerado, int dinero) {
    ofstream archivo(ARCHIVO_PARTIDA);
    archivo << numeroGenerado << endl;
    archivo << dinero << endl;
    archivo.close();
    cout << "Partida guardada." << endl;
}

// Función para cargar el estado del juego
bool cargarPartida(char* numeroGenerado, int& dinero) {
    ifstream archivo(ARCHIVO_PARTIDA);
    if (!archivo.is_open()) {
        return false;
    }
    archivo >> numeroGenerado;
    archivo >> dinero;
    archivo.close();
    return true;
}

// Función para validar la entrada del usuario
bool validarEntrada(const string& entrada) {
    if (entrada.length() != 4) {
        return false;
    }
    for (char c : entrada) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función para validar la opción del menú
bool validarOpcionMenu(const string& entrada) {
    if (entrada.length() != 1) {
        return false;
    }
    if (entrada[0] < '1' || entrada[0] > '4') {
        return false;
    }
    return true;
}

// Función para jugar contra la máquina
void jugarContraMaquina() {
    string nombreUsuario;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreUsuario;

    if (verificarUsuario(nombreUsuario)) {
        cout << "Bienvenido de nuevo, " << nombreUsuario << "!" << endl;
    } else {
        cout << "Usuario nuevo, creando perfil..." << endl;
        agregarUsuario(nombreUsuario);
    }

    char numeroGenerado[5];
    int dinero = 1600;

    // Preguntar si desea cargar una partida guardada
    cout << "¿Desea cargar una partida guardada? (s/n): ";
    char opcion;
    cin >> opcion;
    if (opcion == 's' && cargarPartida(numeroGenerado, dinero)) {
        cout << "Partida cargada." << endl;
    } else {
        generarNumero(numeroGenerado);
    }

    string intento;
    int muertos, heridos;
    int intentosInvalidos = 0;

    cout << "Intenta adivinar el numero de cuatro cifras." << endl;

    do {
        cout << "Ingresa tu adivinanza: ";
        cin >> intento;

        if (!validarEntrada(intento)) {
            intentosInvalidos++;
            if (intentosInvalidos >= 2) {
                cout << "Has ingresado un número inválido dos veces. Has perdido el juego." << endl;
                break;
            }
            cout << "Entrada inválida. Debe ser un número de cuatro cifras. Intentos restantes: " << (2 - intentosInvalidos) << endl;
            continue;
        }

        calcularMuertosYHeridos(numeroGenerado, intento.c_str(), muertos, heridos);

        dinero -= COSTO_TIRADA;
        dinero += (muertos * RECOMPENSA_MUERTO) + (heridos * RECOMPENSA_HERIDO);

        // Emitir sonidos para muertos y heridos
        for (int i = 0; i < muertos; ++i) {
            Beep(1000, 500); // Beep sound for muertos
        }

        for (int i = 0; i < heridos; ++i) {
            Beep(500, 500); // Beep sound for heridos
        }

        if (muertos == 4) {
            cout << "¡Felicidades! Has adivinado el número correctamente." << endl;
            break;
        } else {
            cout << "Muertos: " << muertos << ", Heridos: " << heridos << endl;
            cout << "Dinero restante: $" << dinero << endl;
        }

        if (dinero < COSTO_TIRADA) {
            cout << "Lo siento, has perdido. El número era: " << numeroGenerado << endl;
            break;
        }

        // Preguntar si desea guardar la partida
        cout << "¿Desea guardar la partida? (s/n): ";
        cin >> opcion;
        if (opcion == 's') {
            guardarPartida(numeroGenerado, dinero);
        }
    } while (muertos != 4);

    system("pause");
}

// Función para jugar en modo de dos jugadores
void jugarDosJugadores() {
    string nombreUsuario1, nombreUsuario2;
    cout << "Ingrese el nombre de usuario del Jugador 1: ";
    cin >> nombreUsuario1;
    cout << "Ingrese el nombre de usuario del Jugador 2: ";
    cin >> nombreUsuario2;

    if (verificarUsuario(nombreUsuario1)) {
        cout << "Bienvenido de nuevo, " << nombreUsuario1 << "!" << endl;
    } else {
        cout << "Usuario nuevo, creando perfil..." << endl;
        agregarUsuario(nombreUsuario1);
    }

    if (verificarUsuario(nombreUsuario2)) {
        cout << "Bienvenido de nuevo, " << nombreUsuario2 << "!" << endl;
    } else {
        cout << "Usuario nuevo, creando perfil..." << endl;
        agregarUsuario(nombreUsuario2);
    }

    char numeroGenerado1[5], numeroGenerado2[5];
    cout << nombreUsuario1 << ", ingresa un número de cuatro cifras para que " << nombreUsuario2 << " lo adivine: ";
    cin >> numeroGenerado1;
    cout << nombreUsuario2 << ", ingresa un número de cuatro cifras para que " << nombreUsuario1 << " lo adivine: ";
    cin >> numeroGenerado2;

    string intento;
    int muertos1, heridos1, muertos2, heridos2;
    int vidas1 = VIDAS_INICIALES, vidas2 = VIDAS_INICIALES;
    bool jugador1Gano = false, jugador2Gano = false;
    int intentosInvalidos1 = 0, intentosInvalidos2 = 0;

    cout << "Intenta adivinar el numero de cuatro cifras." << endl;

    while (!jugador1Gano && !jugador2Gano) {
        // Turno del Jugador 1
        cout << nombreUsuario1 << ", ingresa tu adivinanza: ";
        cin >> intento;

        if (!validarEntrada(intento)) {
            intentosInvalidos1++;
            if (intentosInvalidos1 >= 2) {
                cout << "Has ingresado un número inválido dos veces. Has perdido el juego." << endl;
                break;
            }
            cout << "Entrada inválida. Debe ser un número de cuatro cifras. Intentos restantes: " << (2 - intentosInvalidos1) << endl;
            continue;
        }

        calcularMuertosYHeridos(numeroGenerado2, intento.c_str(), muertos1, heridos1);

        vidas1--;

        // Emitir sonidos para muertos y heridos
        for (int i = 0; i < muertos1; ++i) {
            Beep(1000, 500); // Beep sound for muertos
        }

        for (int i = 0; i < heridos1; ++i) {
            Beep(500, 500); // Beep sound for heridos
        }

        if (muertos1 == 4) {
            cout << "¡Felicidades " << nombreUsuario1 << "! Has adivinado el número correctamente." << endl;
            jugador1Gano = true;
            break;
        } else {
            cout << "Muertos: " << muertos1 << ", Heridos: " << heridos1 << endl;
            cout << "Vidas restantes: " << vidas1 << endl;
        }

        if (vidas1 <= 0) {
            cout << "Lo siento " << nombreUsuario1 << ", has perdido. El número era: " << numeroGenerado2 << endl;
            break;
        }

        // Turno del Jugador 2
        cout << nombreUsuario2 << ", ingresa tu adivinanza: ";
        cin >> intento;

        if (!validarEntrada(intento)) {
            intentosInvalidos2++;
            if (intentosInvalidos2 >= 2) {
                cout << "Has ingresado un número inválido dos veces. Has perdido el juego." << endl;
                break;
            }
            cout << "Entrada inválida. Debe ser un número de cuatro cifras. Intentos restantes: " << (2 - intentosInvalidos2) << endl;
            continue;
        }

        calcularMuertosYHeridos(numeroGenerado1, intento.c_str(), muertos2, heridos2);

        vidas2--;

        // Emitir sonidos para muertos y heridos
        for (int i = 0; i < muertos2; ++i) {
            Beep(1000, 500); // Beep sound for muertos
        }

        for (int i = 0; i < heridos2; ++i) {
            Beep(500, 500); // Beep sound for heridos
        }

        if (muertos2 == 4) {
            cout << "¡Felicidades " << nombreUsuario2 << "! Has adivinado el número correctamente." << endl;
            jugador2Gano = true;
            break;
        } else {
            cout << "Muertos: " << muertos2 << ", Heridos: " << heridos2 << endl;
            cout << "Vidas restantes: " << vidas2 << endl;
        }

        if (vidas2 <= 0) {
            cout << "Lo siento " << nombreUsuario2 << ", has perdido. El número era: " << numeroGenerado1 << endl;
            break;
        }
    }

    system("pause");
}

int main() {
    // Configurar la consola para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0)); // Inicializar la semilla para la generación de números aleatorios

    mostrarMenu();

    return 0;
}