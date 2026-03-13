#include <iostream>
using namespace std;

void printMatrix(const int *const *const &mat, const int &r, const int &c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int **exclude(const int *const *const &mat, const int &r, const int &c, const int &M)
{
    int newMatR = 0, newMatC = 0;
    int **newMat = new int *[M - 1];
    for (int i = 0; i < M - 1; i++)
    {
        newMat[i] = new int[M - 1];
    }

    for (int i = 0; i < M; i++)
    {
        if (i == r)
            continue;

        for (int j = 0, newMatC = 0; j < M; j++)
        {
            if (j == c)
                continue;

            newMat[newMatR][newMatC] = mat[i][j];
            // cout << newMat[newMatR][newMatC] << " ";
            newMatC++;
        }
        // cout << "\n";
        newMatC = 0;
        newMatR++;
    }

    return newMat;
}

int calculateDeterminant(const int *const *const &mat, const int &M)
{
    if (M == 1)
    {
        return mat[0][0];
    }
    // base case
    if (M == 2)
    {
        return ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
    }

    int det = 0;
    for (int i = 0; i < M; i++) // iterate through columns
    {
        det += (mat[0][i] * calculateDeterminant(exclude(mat, 0, i, M), M - 1) * pow(-1, i));
    }

    return det;
}

int main()
{
    const int M = 20;

    int **mat = new int *[M];

    int values[M][M] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20}};

    for (int i = 0; i < M; i++)
    {
        mat[i] = new int[M];
        for (int j = 0; j < M; j++)
            mat[i][j] = values[i][j];
    }
    cout << calculateDeterminant(mat, M);
    return 0;
}