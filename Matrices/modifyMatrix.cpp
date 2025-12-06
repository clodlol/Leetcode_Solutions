#include <iostream>
using namespace std;

/*
    This program takes in mxn input matrix and replaces every occurrence of -1 with the largest element in respective column.
*/

int main()
{
    const int m = 3, n = 3;
    int matrix[m][n] = {{1, 2, -1},
                        {4, -1, 6},
                        {7, 8, 9}};

    int modified[m][n] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                int largest = INT_MIN;
                for (int k = 0; k < m; k++)
                {
                    if (matrix[k][j] > largest)
                        largest = matrix[k][j];
                }

                modified[i][j] = largest;
            }
            else
            {
                modified[i][j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << modified[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}