#include <iostream>
#include<ctime>

using namespace std;


void printMatrix(int n,int** matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int** createMatrix(int n)
{
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 50;
        }
    } 
    return matrix;
}


int** calculateProduct(int n, int** matrix1, int** matrix2)
{
    int** result = new int*[n];
    for (int resRow = 0; resRow < n; resRow++)
    {
        result[resRow] = new int[n];
        for (int resCol = 0; resCol < n; resCol++)
        {
            result[resRow][resCol] = 0;
            for (int rowCol = 0; rowCol < n; rowCol++)
                result[resRow][resCol] += matrix1[resRow][rowCol] * matrix2[rowCol][resCol];
        }
    }

    return result;
}


int main()
{
    std::cout << "Welcome To The Matrix Product Software!\n";
    srand(time(NULL));
    cout << "Please input the size of the nxn matrix: ";


    int input;
    cin >> input;
    int const n = input;


    int **matrix1;
    int **matrix2;
    int **result;


    matrix1 = createMatrix(n);
    cout << endl << "Matrix 1: " << endl;
    printMatrix(n, matrix1);

    
    matrix2 = createMatrix(n);
    cout << endl << "Matrix 2: " << endl;
    printMatrix(n, matrix2);


    std::clock_t c_start = std::clock();
    // your_algorithm
    result = calculateProduct(n, matrix1, matrix2);
    std::clock_t c_end = std::clock();

    long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
    std::cout << endl << "CPU time used: " << time_elapsed_ms << " ms\n";

    cout << endl << "Resulting Matrix" << endl;
    printMatrix(n, result);
    

    system("PAUSE");
    return 0;
}