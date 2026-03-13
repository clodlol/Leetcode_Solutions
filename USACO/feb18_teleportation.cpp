#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("teleportation.in");
    ofstream fout("teleportation.out");

    int a, b, x, y; // 3 10 8 2
    fin >> a >> b >> x >> y;

    if ((y >= x) && (abs(y - b) + abs(x - a) < abs(b - a)))
    {
        fout << (abs(y - b) + abs(x - a));
    }
    else if ((y < x) && (abs(x - b) + abs(y - a) < abs(b - a)))
    {
        fout << (abs(x - b) + abs(y - a));
    }
    else
    {
        fout << abs(b - a);
    }

    return 0;
}