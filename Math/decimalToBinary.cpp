#include <iostream>
using namespace std;

int main()
{
    int n = 70;
    for (int i = n; i >= 1; i /= 2)
    {
        cout << i % 2 << " ";
    }

    return 0;
}