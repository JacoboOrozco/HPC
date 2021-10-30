using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>

double x_Origin = 0.0;
double y_Origin = 0.0;
double aproximation_Of_Pi = 0.0;

int newThrow()
{
  int num_Throws;
  cout << "Please enter the number of darts to be thrown at the board" << endl;
  cin >> num_Throws ;
  cout << num_Throws << " darts will be thrown  at the board" << endl;
  return num_Throws;
}

int hitConfirmation(double random_X, double random_Y)
{
    int hit_Counter = 0;
    double distance = sqrt(((random_X - x_Origin)*(random_X - x_Origin)) + ((random_Y - y_Origin)*(random_Y - y_Origin))); 
    cout << "The distance between the origin and the randomly point is: " << distance << endl;
    if (distance <= 1)
    {
        hit_Counter += 1;
    }
    return hit_Counter;

}

void piAproximation(int throw_Counter, int hit_Counter)
{
    double pi_Aprox = 4.0 * hit_Counter/throw_Counter;
    cout << "Pi aproximation = " << pi_Aprox << endl;
}

void throwDarts(int num_Throws)
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
        cout << "Random x coordinte = " << random_X << endl;
        cout << "Random y coordinte = " << random_Y << endl;
        hit_Counter += hitConfirmation(random_X, random_Y);
        throw_Counter += 1;
    }
    cout << "Amount of darts thrown: " << throw_Counter << endl;
    cout << "How many darts hit the circle: " << hit_Counter << endl;
    piAproximation(throw_Counter, hit_Counter);

}

int main()
{
    cout << "Welcome to the dartboard algorith for aproximating PI" << endl;
    cout << "The circle origin coordinates are: " << "["<< x_Origin << "," << y_Origin <<"]"<< endl;

    cout << endl;
    int num_Throws;
    num_Throws = newThrow();
    throwDarts(num_Throws);
}