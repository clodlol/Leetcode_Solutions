#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w1 = 2, w2 = 4, w3 = 6, x = 10;
    vector<double> times;
    for (int a = 1; a <= x; ++a)
    {
        for (int b = 0; b <= x - a; ++b)
        {
            double t1 = (w1 / 2) * (1 + x - a - b);
            double t2 = (w2 / 2) * (1 + a - b);
            double t3 = (w3 / 2) * (1 + b);
            cout << "w1: " << (double)(t1) << "\n";
            cout << "w2: " << (double)(t2) << "\n";
            cout << "w3: " << (double)(t3) << "\n";
            cout << "s: " << (t1 + t2 + t3) << "\n";
            cout << "\n";

            times.push_back(t1 + t2 + t3);
        }
    }
    return 0;
}