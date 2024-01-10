#include <iostream> 
#include <string>
#include <chrono> // para poder camuflar los barcos a los 5 segundos
#include <thread> // para poder camuflar los barcos
#include <vector> // Utilizare la libreria vector para almacenar los barcos como matrices de tamaño dinamico.
#include <cstdlib> // Libreria que contiene los comandos para la generacion de valores aleatorios. En este caso rand y srand
#include <ctime> // Esta libreria la usare para las semillas a la hora de la generacion de valores aleatorios

using namespace std;

const int N_col = 10;
const int N_fil = 10;

// Función para imprimir el tablero
void PRINT_tablero(const vector<vector<char>>& TABLERO) { // indicamos la constante (para que la funcion no pueda modificarla de ninguna manera) vector como vector de vectores en la matriz
    for (int h = 0; h < N_fil; ++h) { // h para height y lo incrementa hasta llegar al valor de la constante
        for (int w = 0; w < N_col; ++w) { // w para width y lo incrementa hasta llegar al valor de la constante
            cout << TABLERO[h][w] << " ";
        }
        cout << endl; // el salto de linia despues de la generacion de cada uno
    }
}

// Función para inicializar el tablero
void START_tablero(vector<vector<char>>& TABLERO) { // lo mismo del print pero esta vez no declaramos la constante ya que mas tarde ha de ser modificado dentro de la funcion
    for (int h = 0; h < N_fil; ++h) {
        for (int w = 0; w < N_col; ++w) {
            TABLERO[h][w] = '~';
        }
    }
}

// Función para colocar un barco en el tablero
bool COLOCAR_barcos(vector<vector<char>>& TABLERO, int SIZE_barco) {
    int direction = rand() % 2; // 0 para horizontal, 1 para vertical y se genera el valor aleatoriamente, el %2 hace que el valor sea menor al 2 excluyendo al mismo (valores negativos excluidos)
    int fil, col;

    if (direction == 0) { // CASO HORIZONTAL
        fil = rand() % N_fil;
        col = rand() % (N_col - SIZE_barco + 1); // ```rand() % (N_col - SIZE_barco + 1)``` es lo que hace que los barcos vayan en las COLUMNAS para hacerlo HORIZONTAL en este caso

        for (int i = 0; i < SIZE_barco; ++i) {
            if (TABLERO[fil][col + i] != '~') {
                return false; // No se puede colocar el barco aquí
            }
        }

        for (int i = 0; i < SIZE_barco; ++i) {
            TABLERO[fil][col + i] = '0' + SIZE_barco; // Coloca el barco
        }
    } else { // CASO VERTICAL
        fil = rand() % (N_fil - SIZE_barco + 1);//```rand() % (N_col - SIZE_barco + 1)``` es lo que hace que los barcos vayan en las FILAS para hacerlo VERTICAL en este caso
        col = rand() % N_col;

        for (int i = 0; i < SIZE_barco; ++i) {
            if (TABLERO[fil + i][col] != '~') {
                return false; // No se puede colocar el barco aquí
            }
        }

        for (int i = 0; i < SIZE_barco; ++i) {
            TABLERO[fil + i][col] = '0' + SIZE_barco; // Coloca el barco
        }
    }
    return true;
}

void camuflarBarcos(vector<vector<char>>& TABLERO) {
    for (int h = 0; h < N_fil; ++h) {
        for (int w = 0; w < N_col; ++w) {
            if (TABLERO[h][w] != '~') { // Si no es agua
                TABLERO[h][w] = '~'; // Cambia a agua
            }
        }
    }
}

bool ATACAR(vector<vector<char>>& TABLERO, int fila, int columna) {
    if (TABLERO[fila][columna] != '~' && TABLERO[fila][columna] != 'O' && TABLERO[fila][columna] != 'X') {
        TABLERO[fila][columna] = 'X'; // Marcar acierto
        return true;
    } else {
        TABLERO[fila][columna] = 'O'; // Marcar fallo
        return false;
    }
}

void PEDIR_coordenadas(int& fila, int& columna) {
    cout << "Ingresa fila y columna: ";
    cin >> fila >> columna;
}

int main() {
    srand(time(NULL)); // Semilla para los números aleatorios

    vector<vector<char>> TABLERO1(N_fil, vector<char>(N_col));
    vector<vector<char>> TABLERO2(N_fil, vector<char>(N_col));

    START_tablero(TABLERO1);
    START_tablero(TABLERO2);

    // Intenta colocar los barcos de diferentes tamaños en cada tablero
    int TAMAÑO_barcos[] = {3, 4, 5, 6}; // Decalramos el array de los tamaños para despues se utilice el listado ordenado para ser llamado en COLOCAR_barcos

    for (int size : TAMAÑO_barcos) {
        while (!COLOCAR_barcos(TABLERO1, size)); // Coloca cada barco en el tablero 1, el COLOCAR_barcos al ser bool indicamos que mientras siga en false con "!" coloque
        while (!COLOCAR_barcos(TABLERO2, size)); // Coloca cada barco en el tablero 2, el COLOCAR_barcos al ser bool indicamos que mientras siga en false con "!" coloque
    }
        // Imprime los tableros con los barcos colocados
    cout << "Tablero jugador 1" << endl;
    PRINT_tablero(TABLERO1);
    cout << "\nTablero jugador 2" << endl; // el /n se usa para que haya espacio entre el tablero n1 y el titulo de el tablero n2
    PRINT_tablero(TABLERO2);
    cout<<"\n"<<endl;


    this_thread::sleep_for(chrono::seconds(10));

    // Camuflar los barcos
    camuflarBarcos(TABLERO1);
    camuflarBarcos(TABLERO2);

    // Detectaremos el sistema operativo y haremos el clear correspondiente (Chat GPT ha ayudado a esto, no tenia ni idea que esto era posible en cpp)
    #ifdef _WIN32
    system("cls"); // Si es Windows, usa cls
    #else
    system("clear"); // En cualquier otro caso (Unix, Linux, macOS), usa clear
    #endif

    // Vuelve a imprimir los tableros con los barcos camuflados pasados esos 10 segundos
    cout << "Tablero jugador 1" << endl;
    PRINT_tablero(TABLERO1);
    cout << "\nTablero jugador 2" << endl;
    PRINT_tablero(TABLERO2);
    
    int fila, columna;
    bool acierto;
    bool juegoTerminado = false; // Mientras esto se mantenga en FALSE no terminara la partida

 
