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
    cout << "Please input the size of the nxn matrix";
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


    result = calculateProduct(n, matrix1, matrix2);
    cout << endl << "Resulting Matrix 2" << endl;
    printMatrix(n, result);
    
    system("PAUSE");
    return 0;
}