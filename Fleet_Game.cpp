#include <iostream>
#include <string>
#include <cstdlib> // Para poder utilizar valores aleatorios con srand o rand
#include <ctime>   // Para poder hacer un random distinto cada vez que se juege el juego (sino saldra siempre la misma combinacion de barcos) [segun lo que dijiste en clase o eso entendi]
using namespace std;

const int N_col = 10;
const int N_fil = 10;

// Funcion para imprimir el tablero
void PRINT_tablero(const string& titulo, const string tablero[N_col][N_fil]) {
    cout << titulo << endl;

    // Imprimir los números de columna
    cout << "   "; // Espacios para alinear con las filas
    for (int j = 1; j <= N_col; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < N_fil; i++) {
        // Imprimir el número de fila
        cout << i + 1 << " ";
        if (i < 9) cout << " "; // Añadir un espacio extra para alinearlo y que quede gucci

        for (int j = 0; j < N_col; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;  // Dejamos una línea vacía al final del tablero la cual no cuenta dentro del tablero y sirve para dar espacio al imput del usuario
}

bool ESPACIO_disponible(const string tablero[N_col][N_fil], int fila, int columna, int tamano, bool horizontal) {
    // Verifica si hay espacio para colocar el barco
    if (horizontal) {
        if (columna + tamano > N_col) return false; // Comprueba límites del tablero
        for (int j = columna; j < columna + tamano; j++) {
            if (tablero[fila][j] != "~ ") return false; // Comprueba si la celda está ocupada
        }
    } else {
        if (fila + tamano > N_fil) return false; // Comprueba límites del tablero
        for (int i = fila; i < fila + tamano; i++) {
            if (tablero[i][columna] != "~ ") return false; // Comprueba si la celda está ocupada
        }
    }
    return true;
}

// Funcion para la colocacion de los barcos en el tablero
void COLOCAR_barco(string tablero[N_col][N_fil], int tamano) {
    bool colocado = false; // Lo declaro como false para realizar la comprovacion
    while (!colocado) { // la ! indica que colocado sigue en false por eso utilizo un bucle de tipo while
        int fila = rand() % N_fil;
        int columna = rand() % N_col;
        bool horizontal = rand() % 2; // 0 o 1, para decidir si el varco va en horizontal (1) o vertical (0) se utiliza %2 para indicar que es un numero menor a el indicado y no puede ser el propio valor

        if (ESPACIO_disponible(tablero, fila, columna, tamano, horizontal)) {
            for (int i = 0; i < tamano; i++) {
                if (horizontal) {
                    tablero[fila][columna + i] = "+ "; // "+" representa un barco
                } else {
                    tablero[fila + i][columna] = "+ ";
                }
            }
            colocado = true;
        }
    }
}

void COLOCAR_barcos(string tablero[N_col][N_fil]) {
    srand(time(0)); // Srand generara los valores aleatorios para las ubicaciones de los barcos segun el tiempo
    // Definimos las dimensiones de los barcos
    COLOCAR_barco(tablero, 3);
    COLOCAR_barco(tablero, 4);
    COLOCAR_barco(tablero, 5);
    COLOCAR_barco(tablero, 6);
} //no me preguntes mucho el formato para esto, lo ha explicado un tipo en stackoverflow


// Asignamos un caracter para el tablero y colocamos los barcos
void START_tablero(string tablero[N_col][N_fil], const string& caracter) {
    for (int i = 0; i < N_fil; i++) {
        for (int j = 0; j < N_col; j++) {
            tablero[i][j] = caracter;
        }
    }
    COLOCAR_barcos(tablero); // Una vez el tablero esta iniciado, colocamos los barcos
}

void Seleccionar_coordenadas(string tablero[N_col][N_fil]) {
    int fila, columna;

    cout << "Ingrese la fila (1-" << N_fil << "): ";
    cin >> fila;
    fila--; // Ajuste del array para que el 0-0 sea el 1-1

    cout << "Ingrese la columna (1-" << N_col << "): ";
    cin >> columna;
    columna--; // Ajuste del array para que el 0-0 sea el 1-1

    if (fila >= 0 && fila < N_fil && columna >= 0 && columna < N_col) {
        tablero[fila][columna] = "X "; // Casilla seleccionada
    }
    else { // Error: Coordenadas fuera de rango
        cout << "Apunta bien desgracia humana" << endl;
    }
}

void JugarTurnos(string tablero1[N_col][N_fil], string tablero2[N_col][N_fil]) {
    bool finDelJuego = false;
    while (!finDelJuego) {

        // Turno del jugador 1
        Seleccionar_coordenadas(tablero1);
        PRINT_tablero("TABLERO 1 ACTUALIZADO", tablero1);

        // Comprobar condición de salida

        if (finDelJuego) break;

        // Turno del jugador 2
        Seleccionar_coordenadas(tablero2);
        PRINT_tablero("TABLERO 2 ACTUALIZADO", tablero2);

        // Comprobar condición de salida
    }
}

void MostrarMenu() {
    cout << "Bienvenido a FLEET_GAME" << endl;
    cout << "1. Funciones de Administrador" << endl;
    cout << "2. Jugador vs Jugador" << endl;
    cout << "3. Jugador vs IA" << endl;
    cout << "Seleccione una opción: ";
}

void AdministrarMenu(string tablero1[N_col][N_fil], string tablero2[N_col][N_fil]) {
    int opcion;
    MostrarMenu();
    cin >> opcion;

    switch (opcion) {
        case 1:
            // Implementar las funciones de administrador
            cout << "Accediendo a funciones de administrador..." << endl;
            break;
        case 2:
            START_tablero(tablero1, "~ ");
            START_tablero(tablero2, "~ ");
            JugarTurnos(tablero1, tablero2);
            break;
        case 3:
            // Implementar la lógica para Jugador vs IA
            cout << "Modo Jugador vs IA aún no implementado." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            AdministrarMenu(tablero1, tablero2); // Llamada recursiva para opción inválida
            break;
    }
}

int main() {
    string tablero1[N_col][N_fil];
    string tablero2[N_col][N_fil];

    AdministrarMenu(tablero1, tablero2);

    return 0;
}
