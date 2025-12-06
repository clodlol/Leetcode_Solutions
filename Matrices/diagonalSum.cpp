#include <iostream>
using namespace std;

int main()
{
    const int m = 4, n = 4;
    int matrix[m][n] = {{1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1}};
    if (m != n)
    {
        cout << "Not a square matrix!" << endl;
        system("pause");
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < m * n; i++)
    {
        if ((i / n) == (i % n) || ((i / n) + (i % n)) == (m-1))
            sum += matrix[i / n][i % n];
    }

    cout << "The sum of the diagonals is: " << sum << endl;

    system("pause");
    return 0;
}