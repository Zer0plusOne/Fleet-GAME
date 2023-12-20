#include <iostream>
#include <string>
using namespace std;

// Declaramos las dimensiones de nuestro tablero
const int N_col = 10;
const int N_fil = 10;

// Lineas vacias para que quede bonito todo
void Void() {
    string ESPACIO{ " " };

    cout << ESPACIO << endl;
};

// Titulo del primer tablero
void Title1() {
    string TABLERO1{ "TABLERO 1" };
    
    cout << TABLERO1 << endl;

       
};
// Función void que imprime el tablero 1
void Print_tablero1() {
    string TABLERO1[N_col][N_fil]{
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "}
    };

    // Imprime el tablero
    for (int i = 0; i < N_fil; i++) {
        for (int j = 0; j < N_col; j++) {
            cout << TABLERO1[i][j];
        }
        cout << endl;
    }
}
void Title2() {
    string TABLERO2{ "TABLERO 2" };

    cout << TABLERO2 << endl;
}
void Print_tablero2() {
    string TABLERO2[N_col][N_fil]{
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "},
        {"# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# ", "# "}
    };

    // Imprime el tablero
    for (int i = 0; i < N_fil; i++) {
        for (int j = 0; j < N_col; j++) {
            cout << TABLERO2[i][j];
        }
        cout << endl;
    }
};

// Funcion principal del codigo
int main() {
    Title1();
    Print_tablero1();
    Void();
    Title2();
    Print_tablero2();
    return 0;  // Declaración de retorno que todo va correcto
}