#include <iostream>
#include <pthread.h>
#include<ctime>
using namespace std;

#define MAX 16

#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matCSecuential[MAX][MAX];
int matCParallel[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
  for (int i = 0; i < MAX; i++)
  	for (int j = 0; j < MAX; j++)
  		for (int k = 0; k < MAX; k++)
  			matCParallel[i][j] += matA[i][k] * matB[k][j];
    return NULL;
}

void paralelismo()
{
  cout << endl << "ESTE ES EL TIEMPO PARALELO" << endl;
  pthread_t threads[MAX_THREAD];
  std::clock_t c_start = std::clock();
  int* p;
  pthread_create(&threads[MAX_THREAD], NULL, multi, (void*)p);
  pthread_join(threads[MAX_THREAD], NULL);
  std::clock_t c_end = std::clock();
  long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
  std::cout << endl << "CPU time used: " << time_elapsed_ms << " ms\n";

  cout << endl << "Multiplication of A and B" << endl;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++)
      cout << matCParallel[i][j] << " ";
    cout << endl;
  }
}

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


	cout << endl
		<< "Matrix A" << endl;
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

  cout << endl << "ESTE ES EL TIEMPO SECUENCIAL" << endl;
  cout << endl << "Matrix C" << endl;
  std::clock_t c_start1 = std::clock();
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
        for (int k = 0; k < MAX; k++)
            matCSecuential[i][j] += matA[i][k] * matB[k][j];
            cout << matCSecuential[i][j] << " ";
    }
    cout << endl;
  }
  std::clock_t c_end1 = std::clock();
  long double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;
  std::cout << endl << "CPU time used: " << time_elapsed_ms1 << " ms\n";

  paralelismo();




	return 0;
}
