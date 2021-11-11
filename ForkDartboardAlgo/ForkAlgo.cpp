using namespace std;

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <random>
#include <unistd.h> 
#include <sys/wait.h>

double x_Origin = 0.0;
double y_Origin = 0.0;
int num_Of_Throws = 32768;

pid_t process_1;
pid_t process_2;


int hitConfirmation(double random_X, double random_Y)
{
    int hit_Counter = 0;
    double distance = sqrt(((random_X - x_Origin)*(random_X - x_Origin)) + ((random_Y - y_Origin)*(random_Y - y_Origin))); 
    //cout << "The distance between the origin and the randomly point is: " << distance << endl;
    if (distance <= 1)
    {
        hit_Counter += 1;
    }
    return hit_Counter;

}

int throwDarts(int num_Throws)
{
    int throw_Counter = 0;
    int hit_Counter = 0;
    std::random_device rd;
    std::default_random_engine generator(rd()); //rd provides a random seed
    std::uniform_real_distribution<double> distribution(-1,1);
    while(throw_Counter < num_Throws)
    {
        double random_X = distribution(generator);
        double random_Y = distribution(generator);
        //cout << "Random x coordinte = " << random_X << endl;
        //cout << "Random y coordinte = " << random_Y << endl;
        hit_Counter += hitConfirmation(random_X, random_Y);
        throw_Counter += 1;
    }
    //cout << "Amount of darts thrown: " << throw_Counter << endl;
    //cout << "How many darts hit the circle: " << hit_Counter << endl;
    return hit_Counter;
}

void parallelism()
{
    int hits_Process_1 = 0;
    int hits_Process_2 = 0;
    int total_Hits = 0;

    long int first_Half_Throws = num_Of_Throws/2;
    long int second_Half_Throws = num_Of_Throws - first_Half_Throws;    

    std::clock_t c_start1 = std::clock();

    hits_Process_1 = throwDarts(first_Half_Throws);
    cout << endl <<  "Number of hits process 1: " << hits_Process_1 << endl;

    pid_t pid = fork();

    if(pid)
    {
        int p2 = 0;
        if(p2 < second_Half_Throws)
        {
            //cout<<"Process 2" << endl;
            hits_Process_2 = throwDarts(second_Half_Throws);
            cout << endl <<"Number of hits process 2: " << hits_Process_2 << endl;
            total_Hits = hits_Process_1 + hits_Process_2;

            cout << endl << "Number of total hits: " << total_Hits << endl;
            double pi_Aprox = 4.0 * total_Hits/num_Of_Throws;

            cout << "Pi Aproximation: " << pi_Aprox << endl;

            std::clock_t c_end1 = std::clock();
            long double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;
            std::cout << endl << "CPU time used: " << time_elapsed_ms1 << " ms\n";
            exit(0);
        }
        
    } 

}

int main()
{
    cout << "Welcome to the dartboard algorith for aproximating PI" << endl;
    cout << "The circle origin coordinates are: " << "["<< x_Origin << "," << y_Origin <<"]"<< endl;
    cout << endl;
    int total_Hits = 0;
    

    parallelism();


    exit(0);

}