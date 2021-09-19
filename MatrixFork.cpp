#include <iostream>
#include<ctime>
#include<cmath>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

#define MAX 5


int matA[MAX][MAX];
int matB[MAX][MAX];
int matCSecuential[MAX][MAX];
int matCParallel[MAX][MAX];
int step_i = 0;
int half = round((MAX/2));

pid_t process_1;
pid_t process_2;


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

  cout << endl << "Sequential Time: " << endl;
  cout << endl << "Matrix C" << endl;
  std::clock_t c_start1 = std::clock();
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
        for (int k = 0; k < MAX; k++)
            matCSecuential[i][j] += matA[i][k] * matB[k][j];
            cout << matCSecuential[i][j] << "\t";
    }
    cout << endl;
  }
  std::clock_t c_end1 = std::clock();
  long double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;
  std::cout << endl << "CPU time used: " << time_elapsed_ms1 << " ms\n";


  cout<<"Parallel execution"<<endl;

  pid_t pid = fork();
  if (pid)
  {
    process_1 = pid;
    pid = fork();
  }
  if (pid)
  {
      process_2 = pid;
      pid = fork();
  }

  //cout<<"Proces 1"<<endl;
  if(process_1 == 0)
  {
    int P1 = 0;
    int firstHalf = 0 + half;
    if (P1 < firstHalf)
    {
      for (int i = 0; i < MAX; i++)
      {
        for (int j = 0; j < MAX; j++)
        {
          for (int k = 0; k < MAX; k++)
          {
            matCParallel[i][j] += matA[i][k] * matB[k][j];
          }
          //cout<<matCParallel[i][j]<< "\t";
        }
        //cout<<endl;
      }
    }
    exit(0);
  }
  //cout<<"Process 2"<<endl;
  if(process_2 == 0)
  {
    int P2 = half;
    int secondHalf = half + half;
    if(P2 >= half && P2 <= secondHalf)
    {
      for (int i = 0; i < MAX; i++)
      {
        for (int j = 0; j < MAX; j++)
        {

          for (int k = 0; k < MAX; k++)
          {
            matCParallel[i][j] += matA[i][k] * matB[k][j];
          }
          cout<<matCParallel[i][j] << "\t";
        }
        cout<<endl;
      }
    }
    exit(0);
  }

  waitpid(process_1, NULL, 0);
  waitpid(process_2, NULL, 0);



	return 0;
}
