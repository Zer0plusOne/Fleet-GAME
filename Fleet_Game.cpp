#include <iostream>
#include <string>
using namespace std;

const int N_col = 10;
const int N_fil = 10;

// Funcion inicial para imprimir el tablero
void Print_tablero(const string& titulo, const string tablero[N_col][N_fil]) {
    cout << titulo << endl;
    for (int i = 0; i < N_fil; i++) {
        for (int j = 0; j < N_col; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;  // Dejamos una linia vacia al final del tablero
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

    cout << "Ingrese la fila (0-" << N_fil - 1 << "): ";
    cin >> fila;

    cout << "Ingrese la columna (0-" << N_col - 1 << "): ";
    cin >> columna;

    // Existen esas coordenadas introducidas por el usuario?
    if (fila >= 0 && fila < N_fil && columna >= 0 && columna < N_col) {
        tablero[fila][columna] = "X "; // Caracter seleccionado
    }
    else { // Error: Coordenadas fuera de rango
        cout << "Apunta bien desgracia humana" << endl;
    }
}

int main() {
    string tablero1[N_col][N_fil];
    START_tablero(tablero1, "# ");
    Print_tablero("TABLERO 1", tablero1);

    // Permitir al usuario seleccionar coordenadas para el primer tablero
    
    Seleccionar_coordenadas(tablero1);
    Print_tablero("TABLERO 1 ACTUALIZADO", tablero1);

    // Puedes hacer lo mismo para el segundo tablero según tus necesidades
    string tablero2[N_col][N_fil];
    START_tablero(tablero2, "* ");
    Print_tablero("TABLERO 2", tablero2);

    // Permitir al usuario seleccionar coordenadas para el segundo tablero
    Seleccionar_coordenadas(tablero2);
    Print_tablero("TABLERO 2 ACTUALIZADO", tablero2);

    return 0;
}
