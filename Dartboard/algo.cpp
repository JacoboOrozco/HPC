using namespace std;

#include <iostream>
#include <stdlib.h>
#include<ctime>
#include <math.h>
#include <random>
#include <pthread.h>
#include <omp.h>

#define NUM_THREADS 2

double x_Origin = 0.0;
double y_Origin = 0.0;
int num_Throws = 32768;



int hitConfirmation(double random_X, double random_Y)
{
    int throw_Counter = 0;
    int hit_Counter = 0;
    double distance = sqrt(((random_X - x_Origin)*(random_X - x_Origin)) + ((random_Y - y_Origin)*(random_Y - y_Origin))); 
    //cout << "The distance between the origin and the randomly point is: " << distance << endl;
    
    if (distance <= 1)
    {
        hit_Counter += 1;
    }
    return hit_Counter;
}


long int throwDarts(long int number_Of_throws)
{
    int throw_Counter;
    long int hit_Counter = 0;
    //cout << endl <<"THIS IS THE AMOUT OF DARTS THROWN IN THIS THREAD: " << number_Of_throws << endl;
    std::random_device rd;
    std::default_random_engine generator(rd()); //rd provides a random seed
    std::uniform_real_distribution<double> distribution(-1,1);

    for(throw_Counter = 0; throw_Counter < number_Of_throws; throw_Counter ++)
    {
        double random_X = distribution(generator);
        double random_Y = distribution(generator);

        //cout << endl << "Random x coordinte = " << random_X << endl;
        //cout << "Random y coordinte = " << random_Y << endl;

        hit_Counter += hitConfirmation(random_X, random_Y);
    }
    //cout << endl << "Amount of darts thrown: " << throw_Counter << endl;
    //cout << endl << "How many darts hit the circle: " << hit_Counter << endl;

    return hit_Counter;
}

int main()
{
    cout << "Welcome to the dartboard algorith for aproximating PI" << endl;
    cout << "The circle origin coordinates are: " << "["<< x_Origin << "," << y_Origin <<"]"<< endl;
    cout << endl;

    int n_Hits1 = 0;
    int n_Hits2 = 0;
    int number_Of_Hits = 0;

    pthread_t thread1;
    pthread_t thread2;
    int i;
    int darts_Group1;
    int darts_Group2;
    long int first_Half_Throws = num_Throws / 2;
    long int second_Half_Throws = num_Throws - first_Half_Throws;

    //cout << endl << "THIS IS THE FIRST HALF OF THE THROWS: " << first_Half_Throws << endl;
    //cout << endl << "THIS IS THE SECOND HALF OF THE THROWS: " << second_Half_Throws << endl;
    //cout << endl << "THIS IS THE TOTAL AMOUNT OF THROWS: " << first_Half_Throws + second_Half_Throws << endl;


    std::clock_t c_start1 = std::clock();

    #pragma omp parallel for
    for(int i = 0; i < NUM_THREADS; i++)
    {
        n_Hits1 = throwDarts(first_Half_Throws);
        n_Hits2 = throwDarts(second_Half_Throws);
    }



    cout << "Number of hits from thread 1: "<< n_Hits1 << endl;
    cout << "Number of hits from thread 2: "<< n_Hits2 << endl;   

    number_Of_Hits = n_Hits1 + n_Hits2;
    cout << endl << "Number of hits in main: " << number_Of_Hits << endl;
    double pi_Aprox = 4.0 * number_Of_Hits/num_Throws;
    cout << "Pi aproximation = " << pi_Aprox << endl;

    cout << endl << "ESTE ES EL TIEMPO PARALLELO" << endl;
    std::clock_t c_end1 = std::clock();
    long double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;
    std::cout << endl << "CPU time used: " << time_elapsed_ms1 << " ms\n";
}