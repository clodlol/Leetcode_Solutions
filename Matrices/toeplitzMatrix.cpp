#include <iostream>
using namespace std;

/*
    This program takes every small diagonal of a matrix and prints it.
*/

int main()
{
    const int m = 3, n = 4;
    int matrix[m][n] = {{1, 2, 3, 4},
                        {5, 1, 2, 3},
                        {9, 5, 1, 2}};

    for (int i = m - 2; i >= 0; i--)
    {
        int internalI = i;
        int internalJ = 0;
        int prev = matrix[i][0];
        bool matching = true;
        while (internalJ < n - i - 1)
        {
            cout << matrix[internalI][internalJ] << " ";

            internalI++;
            internalJ++;
        }
        cout << endl;
    }

    for (int j = 1; j < n - 1; j++)
    {
        int internalI = 0;
        int internalJ = j;
        int prev = matrix[0][j];
        bool matching = true;
        while (internalI < m - j + 1)
        {
            cout << matrix[internalI][internalJ] << " ";

            internalI++;
            internalJ++;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}