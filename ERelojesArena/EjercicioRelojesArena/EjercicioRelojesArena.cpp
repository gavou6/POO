// EjercicioRelojesArena.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Gabriel Uribe Sandoval 23310264

#include <iostream>

using namespace std;

const int MAX = 100; 

void leerMatriz(int matriz[MAX][MAX], int n) {
    cout << "Ingresa los valores de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
}

int sumaRelojArena(int matriz[MAX][MAX], int i, int j) {
    return matriz[i - 1][j - 1] + matriz[i - 1][j] + matriz[i - 1][j + 1] 
        + matriz[i][j]                                        
        + matriz[i + 1][j - 1] + matriz[i + 1][j] + matriz[i + 1][j + 1]; 
}

void encontrarRelojArenaMaximo(int matriz[MAX][MAX], int n, int& maxSuma, int& maxI, int& maxJ) {
    maxSuma = -10000;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sumaActual = sumaRelojArena(matriz, i, j);
            if (sumaActual > maxSuma) {
                maxSuma = sumaActual;
                maxI = i;
                maxJ = j;
            }
        }
    }
}

int main() {

    int n;
    int matriz[MAX][MAX];
    cout << "Ingresa el tamano de la matriz (n x n): ";
    cin >> n;
    if (n < 3) {
        cout << "El tamano de la matriz debe ser al menos 3x3 para formar un reloj de arena." << endl;
        return 1;
    }
    leerMatriz(matriz, n);
    int maxSuma, maxI, maxJ;
    encontrarRelojArenaMaximo(matriz, n, maxSuma, maxI, maxJ); 
    cout << "El reloj de arena con mayor valor tiene una suma de: " << maxSuma << endl;
    return 0;
}





// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
