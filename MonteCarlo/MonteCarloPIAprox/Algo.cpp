using namespace std;

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <random>
#include <unistd.h> 
#include <sys/wait.h>


pid_t process_1;
pid_t process_2;

// A mayor intervalo, mayor número de dígitos significativos para la precision de X y Y
#define INTERVALO 256



int intervals(int numero_intervalo)
{
    int puntosGenerados = 0;
    int puntos = 0;

    srand(time(NULL));

    while (puntosGenerados < numero_intervalo)
    {
        double rand_X = double(rand() % (INTERVALO + 1)) / INTERVALO;
        double rand_Y = double(rand() % (INTERVALO + 1)) / INTERVALO;
 
        // Distancia de (x, y) al origen
        double distancia_origen = rand_X * rand_X + rand_Y * rand_Y;
 
        // Verificar si (x, y) esta en R=1
        if (distancia_origen <= 1)
            puntos++;

        puntosGenerados += 1;
    }

    //cout << endl << "Puntos en el intervalo: " << puntosGenerados << endl;
    //cout << endl << "Puntos dentro del rango: " << puntos << endl;

    return puntos;
}

void parallelism()
{
    int proceso_puntos1 = 0;
    int proceso_puntos2 = 0;
    int total_puntos = 0;

    long int primer_intervalo = INTERVALO/2;
    long int segundo_intervalo = INTERVALO - primer_intervalo;    

    std::clock_t c_start1 = std::clock();

    proceso_puntos1 = intervals(primer_intervalo);
    //cout << endl <<  "Numero de puntos en el proceso 1: " << proceso_puntos1 << endl;

    pid_t pid = fork();

    if(pid)
    {
        int p2 = 0;
        if(p2 < segundo_intervalo)
        {
            //cout<<"Process 2" << endl;
            proceso_puntos2 = intervals(segundo_intervalo);
            //cout << endl <<"Numero de puntos en el proceso 2: " << proceso_puntos2 << endl;
            total_puntos = proceso_puntos1 + proceso_puntos2;

            //cout << endl << "Total de puntos: " << total_puntos << endl;
            double pi_Aprox = 4.0 * total_puntos/INTERVALO;

            cout << "Aproximacion de PI: " << pi_Aprox << endl;

            std::clock_t c_end1 = std::clock();
            long double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;
            std::cout << endl << "CPU time used: " << time_elapsed_ms1 << " ms\n";
            exit(0);
        }
        
    } 

}

 
int main()
{
    int total_puntos = 0;

    parallelism();


    exit(0);
}