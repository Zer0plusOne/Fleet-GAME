#include <iostream> 
#include <string>
#include <chrono> // para poder camuflar los barcos a los 5 segundos
#include <thread> // para poder camuflar los barcos
#include <vector> // Utilizare la libreria vector para almacenar los barcos como matrices de tamaño dinamico.
#include <cstdlib> // Libreria que contiene los comandos para la generacion de valores aleatorios. En este caso rand y srand
#include <ctime> // Esta libreria la usare para las semillas a la hora de la generacion de valores aleatorios

/* en esta seccion que voy a marcar me voy a permitir colocar un arte ascii para que la imrima en la pantalla al iniciar el juego */

/*
    ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
    ██░▄▄▄██░█████░▄▄▄██░▄▄▄█▄▄░▄▄█████░▄▄░█░▄▄▀██░▄▀▄░██░▄▄▄█
    ██░▄▄███░█████░▄▄▄██░▄▄▄███░███▀▀██░█▀▀█░▀▀░██░█░█░██░▄▄▄█
    ██░█████░▀▀░██░▀▀▀██░▀▀▀███░███▄▄██░▀▀▄█░██░██░███░██░▀▀▀█
    ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
    By: Guillermo Gómez Sánchez
    Github: github.com/Zer0plusOne
*/

/*---------------------------------------------- INICIO DEL CODIGO PRINCIPAL DEL JUEGO ----------------------------------------------*/

using namespace std;

const int N_col = 10; // Se declaran como constantes ya que son valores los cuales no se han de retocar i/o modificar en ningun momento de la ejecucion del codigo
const int N_fil = 10; // Se declaran como constantes ya que son valores los cuales no se han de retocar i/o modificar en ningun momento de la ejecucion del codigo

// Función para imprimir el tablero
void PRINT_tablero(const vector<vector<char>>& TABLERO) { // indicamos la constante (para que la funcion no pueda modificarla de ninguna manera) vector como vector de vectores en la matriz
    for (int h = 0; h < N_fil; ++h) { // h para height y lo incrementa hasta llegar al valor de la constante
        for (int w = 0; w < N_col; ++w) { // w para width y lo incrementa hasta llegar al valor de la constante
            cout << TABLERO[h][w] << " ";
        }
        cout << endl; // el salto de linia despues de la generacion de cada uno
    }
}

// Función para inicializar el tablero (poner los caracteres de "agua")
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
    int fila, col;

    if (direction == 0) { // CASO HORIZONTAL
        fila = rand() % N_fil;
        col = rand() % (N_col - SIZE_barco + 1); // ```rand() % (N_col - SIZE_barco + 1)``` es lo que hace que los barcos vayan en las COLUMNAS para hacerlo HORIZONTAL en este caso

        for (int i = 0; i < SIZE_barco; ++i) {
            if (TABLERO[fila][col + i] != '~')
            {
                return false; // No se puede colocar el barco aquí
            }
        }

        for (int i = 0; i < SIZE_barco; ++i) {
            TABLERO[fila][col + i] = '0' + SIZE_barco; // Coloca el barco
        }
    }
    else { // CASO VERTICAL
        fila = rand() % (N_fil - SIZE_barco + 1);// ```rand() % (N_col - SIZE_barco + 1)``` es lo que hace que los barcos vayan en las FILAS para hacerlo VERTICAL en este caso
        col = rand() % N_col;

        for (int i = 0; i < SIZE_barco; ++i) {
            if (TABLERO[fila + i][col] != '~') {
                return false; // No se puede colocar el barco aquí
            }
        }

        for (int i = 0; i < SIZE_barco; ++i) {
            TABLERO[fila + i][col] = '0' + SIZE_barco; // Coloca el barco
        }
    }
    return true;
}

bool ATAQUE(vector<vector<char>>& TABLERO, vector<vector<char>>& TABLERO_ataque, int fila, int columna) {
    if (TABLERO[fila][columna] != '~') {
        // Hay un barco, marca con una 'X' y devuelve true.
        TABLERO_ataque[fila][columna] = 'X';
        return true;
    }
    else {
        // No hay barco, marca con una 'O' y devuelve false.
        TABLERO_ataque[fila][columna] = 'O';
        return false;
    }
}

int main() {

    srand(time(NULL)); // Semilla para los números aleatorios

    vector<vector<char>> TABLERO1(N_fil, vector<char>(N_col));  //Creacion de los tableros donde se muestran los barcos de ambos jugadores
    vector<vector<char>> TABLERO2(N_fil, vector<char>(N_col));  //Creacion de los tableros donde se muestran los barcos de ambos jugadores
    vector<vector<char>> TABLERO1_ataque(N_fil, vector<char>(N_col));   //Creacion de los tableros donde interactuaran los jugadores
    vector<vector<char>> TABLERO2_ataque(N_fil, vector<char>(N_col));   //Creacion de los tableros donde interactuaran los jugadores

    START_tablero(TABLERO1);
    START_tablero(TABLERO2);

    START_tablero(TABLERO1_ataque);
    START_tablero(TABLERO2_ataque);

    // Intenta colocar los barcos de diferentes tamaños en cada tablero
    int TAMAÑO_barcos[] = { 3, 4, 5, 6 }; // Decalramos el array de los tamaños para despues se utilice el listado ordenado para ser llamado en COLOCAR_barcos

    for (int size : TAMAÑO_barcos) {
        while (!COLOCAR_barcos(TABLERO1, size)); // Coloca cada barco en el tablero 1, el COLOCAR_barcos al ser bool indicamos que mientras siga en false con "!" coloque
        while (!COLOCAR_barcos(TABLERO2, size)); // Coloca cada barco en el tablero 2, el COLOCAR_barcos al ser bool indicamos que mientras siga en false con "!" coloque
    }
    // Imprime los tableros con los barcos colocados
    cout << "Tablero jugador 1" << endl;
    PRINT_tablero(TABLERO1);
    cout << "\nTablero jugador 2" << endl; // el /n se usa para que haya espacio entre el tablero n1 y el titulo de el tablero n2
    PRINT_tablero(TABLERO2);
    cout << "\n" << endl;


    this_thread::sleep_for(chrono::seconds(10)); // esto lo ha dicho chatGPt (profe porfabor es solo un timeout <3)

    // Detectaremos el sistema operativo y haremos el clear correspondiente (Chat GPT ha ayudado a esto, no tenia ni idea que esto era posible en cpp)
#ifdef _WIN32
    system("cls"); // Si es Windows, usa cls
#else
    system("clear"); // En cualquier otro caso (Linux DISTROS, macOS), usa clear
#endif

    // 
    START_tablero(TABLERO1_ataque);
    START_tablero(TABLERO2_ataque);

    cout << "Tablero jugador 1" << endl;
    PRINT_tablero(TABLERO1_ataque);
    cout << "\nTablero jugador 2" << endl; // el /n se usa para que haya espacio entre el tablero n1 y el titulo de el tablero n2
    PRINT_tablero(TABLERO2_ataque);
    cout << "\n" << endl;

    bool TURNO_jugador1 = true; // Se usara el valor de este boolean como interruptor (switch) entre turnos de JUGADOR1 y JUGADOR2

    int PUNTUACION_jugador1 = 0; // las puntuaciones se utilizaran para poder finalizar la partida en caso de que el jugador alcance el maximo posible (15) 
    int PUNTUACION_jugador2 = 0;

    int fila, columna;
    while (true) { // Bucle del juego (podrías tener una condición de salida)
        cout << (TURNO_jugador1 ? "Turno del Jugador 1" : "Turno del Jugador 2") << endl; // se utilizan los ":" para ir alternando el mensaje segun si es TRUE o FALSE
        cout << "Ingresa fila y columna para atacar: (Fila [ESPACIO] Columna) ";
        cin >> fila >> columna;

        fila--;
        columna--;
        
        if (fila < 0 || fila >= N_fil || columna < 0 || columna >= N_col) {
            cout << "Apunta dentro del tablero listillo" << endl;
            continue; // Vuelve al inicio del bucle para pedir de nuevo las coordenadas ya que el usuario no sabe apuntar

            // Al volver al inicio del bucle volvera a pedir al jugador que le toca ingresar las coordenadas (NO SALTA EL TURNO), por eso el uso de un boolean para el runo del jugador
        }

        // Verifica la validez de las entradas aquí...

        if (TURNO_jugador1) {
            if (ATAQUE(TABLERO2, TABLERO1_ataque, fila, columna)) { // se hace intercalando los tableros y el tablero de ataque para que los jugadores no ataquen sus propios tableros
                cout << "TOCADO" << endl;
                PUNTUACION_jugador1++;
            }
            else {
                cout << "MANCO, apunta mejor" << endl;
            }
        }
        else {
            if (ATAQUE(TABLERO1, TABLERO2_ataque, fila, columna)) {
                cout << "TOCADO" << endl;
                PUNTUACION_jugador2++;
            }
            else {
                cout << "MANCO, apunta mejor" << endl;
            }
        }
        // Verificamos si los jugadores han llegado a la puntuacion maxima para terminar la partida

        if (PUNTUACION_jugador1 == 15){
            cout << "JUGADOR 1 GANA LA PARTIDA  *MUSICA EPICA*" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            exit(0); // utilizo el code "0" ya que no es ningun error que esto ocurra, al contrario, indica que el codigo ha funcionado correctamente en todo momento hasta finalizar la partida 
        }

        if (PUNTUACION_jugador2 == 15) {
            cout << "JUGADOR 2 GANA LA PARTIDA  *MUSICA EPICA*" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            exit(0); // lo mismo que arriba
        }

        PRINT_tablero(TURNO_jugador1 ? TABLERO1_ataque : TABLERO2_ataque); // Para imprimir los tableros al final de cada jugada con los cambios necesarios

        // Cambia el turno (no se necesita especificar que es del jugador 2 en el codigo ya que el valor "FALSE" del boolean "TURNO_jugador1" se entiende como "TURNO_jugador2")
        TURNO_jugador1 = !TURNO_jugador1;
    }
    return 0;
};
