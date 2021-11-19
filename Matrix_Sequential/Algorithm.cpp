#include <iostream>
#include<ctime>
#include<cmath>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

#define MAX 2048


int matA[MAX][MAX];
int matB[MAX][MAX];
int matCSecuential[MAX][MAX];
int matCParallel[MAX][MAX];
int step_i = 0;


int main()
{
  std::cout << "Welcome To The Matrix Product Software!\n";
  srand(time(NULL));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matA[i][j] = rand() % 10;
			matB[i][j] = rand() % 10;
		}
	}

/*
	cout << endl<< "Matrix A" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matA[i][j] << " ";
		cout << endl;
	}
	cout << endl << "Matrix B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matB[i][j] << " ";
		cout << endl;
	}
*/
  cout << endl << "Sequential Time Without Tranposed Matrix: " << endl;
  //cout << endl << "Matrix C" << endl;
  std::clock_t c_start = std::clock();
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
        for (int k = 0; k < MAX; k++)
            matCSecuential[i][j] += matA[i][k] * matB[k][j];
            //cout << matCSecuential[i][j] << "\t";
    }
    //cout << endl;
  }
  std::clock_t c_end = std::clock();
  long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
  std::cout << endl << "CPU time used: " << time_elapsed_ms << " ms\n";

	return 0;
}