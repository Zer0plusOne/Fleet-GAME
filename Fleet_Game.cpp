#include <iostream>
#include <string>
using namespace std;

const int N_col = 10;
const int N_fil = 10;

// Funcion inicial para imprimir el tablero
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
        if (i < 9) cout << " "; // Añadir un espacio extra para alinear si es un dígito

        for (int j = 0; j < N_col; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;  // Dejamos una línea vacía al final del tablero
}

// Asignamos un caracter para el tablero
void START_tablero(string tablero[N_col][N_fil], const string& caracter) {
    for (int i = 0; i < N_fil; i++) {
        for (int j = 0; j < N_col; j++) {
            tablero[i][j] = caracter;
        }
    }
}


// Con esta funcion dejamos al usuario seleccionar coordenadas del tablero
void Seleccionar_coordenadas(string tablero[N_col][N_fil]) {
    int fila, columna;

    cout << "Ingrese la fila (1-" << N_fil << "): ";
    cin >> fila;
    fila--; // Ajuste del array para que el 0-0 sea el 1-1

    cout << "Ingrese la columna (1-" << N_col << "): ";
    cin >> columna;
    columna--; // Ajuste del array para que el 0-0 sea el 1-1

    // Verificamos si el usuario es suficientemente listo como para apuntar dentro del tablero

    if (fila >= 0 && fila < N_fil && columna >= 0 && columna < N_col) {
        tablero[fila][columna] = "X "; // Casilla seleccionada
    }
    else { // Error: Coordenadas fuera de rango
        cout << "Apunta bien desgracia humana" << endl;
    }
}

void JugarTurnos(string tablero1[N_col][N_fil], string tablero2[N_col][N_fil]) {
    bool finDelJuego = false; // Lo dejamos en false para en el momento de volverlo true, termine la partida
    while (!finDelJuego) {

        // Turno del jugador 1
        Seleccionar_coordenadas(tablero1);
        PRINT_tablero("TABLERO 1 ACTUALIZADO", tablero1);

        // Comprobar condición de salida
        // Si se cumple, hacer finDelJuego = true;

        if (finDelJuego) break;

        // Turno del jugador 2
        Seleccionar_coordenadas(tablero2);
        PRINT_tablero("TABLERO 2 ACTUALIZADO", tablero2);

        // Comprobar condición de salida
        // Si se cumple, hacer finDelJuego = true;
    }
}

int main() {
    // Funciones del tablero n1
    string tablero1[N_col][N_fil];
    START_tablero(tablero1, "~ ");
    PRINT_tablero("TABLERO 1", tablero1);

    // Funciones del tablero n2
    string tablero2[N_col][N_fil];
    START_tablero(tablero2, "~ ");
    PRINT_tablero("TABLERO 2", tablero2);

    // Pide los turnos hasta finalizar la partida
    JugarTurnos(tablero1, tablero2);

    return 0;
}
