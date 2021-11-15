#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std; 

// A mayor intervalo, mayor número de dígitos significativos para la precision de X y Y
#define INTERVALO 100

 
int main()
{
    int interval, i;
    double rand_x, rand_y, distancia_origen, pi;
    int puntos = 0, puntosGenerados = 0;
 
    // Inicia rand
    srand(time(NULL));
 
    // Total de números generados = valores posibles de x * valores posibles de y
    for (i = 0; i < (INTERVALO * INTERVALO); i++) {
 
        // Valores aleatorios para X y Y
        rand_x = double(rand() % (INTERVALO + 1)) / INTERVALO;
        rand_y = double(rand() % (INTERVALO + 1)) / INTERVALO;
 
        // Distancia de (x, y) al origen
        distancia_origen = rand_x * rand_x + rand_y * rand_y;
 
        // Verificar si (x, y) esta en R=1
        if (distancia_origen <= 1)
            puntos++;
 
        // Total de puntos generados
        puntosGenerados++;
 
        // Valor estimado de pi después de esta iteracion
        pi = double(4 * puntos) / puntosGenerados;
 
        // Esto lo puede borrar (imprime la estimación por cada intervalo)
        cout << rand_x << " " << rand_y << " " << puntos
             << " " << puntosGenerados << " - " << pi << endl << endl;

    }
 
     cout << "\nAproximación de PI = " << pi
        << "\n";
 
    return 0;
}