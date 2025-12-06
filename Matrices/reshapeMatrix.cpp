#include <iostream>
using namespace std;

/*
    This program takes a matrix and reshapes it into a new matrix with specified dimensions.
*/

int main()
{
    const int m = 2, n = 2;
    int matrix[m][n] = {{1, 2},
                        {3, 4}};
    const int r = 4, c = 1;
    if ((m * n) != (r * c))
    {
        cout << "Not possible!" << endl;
        system("pause");
        return 0;
    }

    int reshape[r][c] = {0};
    int reshapeI = 0, reshapeJ = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            reshape[reshapeI][reshapeJ] = matrix[i][j];

            reshapeJ++;
            if (reshapeJ == c)
            {
                reshapeJ = 0;
                reshapeI++;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << reshape[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}