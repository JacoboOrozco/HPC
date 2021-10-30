using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>

int circle_Origins [2]= {0,0};

int newThrow()
{
  int num_Throws;
  cout << "Please enter the number of darts to be thrown at the board" << endl;
  cin >> num_Throws ;
  cout << num_Throws << " darts will be thrown  at the board" << endl;
  return num_Throws;
}

void throwDarts(int num_Throws)
{
    int random_Coordinates [2] = {0,0};
    int throw_Counter = 0;
    std::random_device rd;
    std::default_random_engine generator(rd()); //rd provides a random seed
    std::uniform_real_distribution<double> distribution(-1,1);
    while(throw_Counter < num_Throws)
    {
        double random_X = distribution(generator);
        double random_Y = distribution(generator);
        cout << "Random x coordinte = " << random_X << endl;
        cout << "Random y coordinte = " << random_Y << endl;
        throw_Counter += 1;
    }
}

int main()
{
    cout << "Welcome to the dartboard algorith for aproximating PI" << endl;
    cout << "The circle origin coordinates are: " << endl;
    for(int i = 0; i < 2; i++)
    {
        cout << circle_Origins[i] << "\t";
    }
    cout << endl;
    int num_Throws;
    num_Throws = newThrow();
    throwDarts(num_Throws);
}