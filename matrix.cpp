#include <iostream>
#include<ctime>

using namespace std;


int main()
{
    std::cout << "Welcome To The Matrix Product Software!\n";
    srand(time(NULL));
    cout << "Please input the size of the nxn matrix";
    int input;
    cin >> input;
    const int n = input;
    int matrix1[n][n];
    int matrix2[n][n];
    int result[n][n];
    cout << "First Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 50;
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Second Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[i][j] = rand() % 50;
            cout << matrix2[i][j] << "\t";
        }
        cout << endl;
    }


    for (int resRow = 0; resRow < n; resRow++)
    {
        for (int resCol = 0; resCol < n; resCol++)
        {
            result[resRow][resCol] = 0;
            for (int rowCol = 0; rowCol < n; rowCol++)
                result[resRow][resCol] += matrix1[resRow][rowCol] * matrix2[rowCol][resCol];
        }
    }


    cout << "Result matrix is \n";
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << result[row][col] << "\t";
        }
        cout << "\n";
    }


    system("PAUSE");

    return 0;

}
