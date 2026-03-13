#include <iostream>
using namespace std;

bool isDieRoll(const int &a, const int &b)
{
    return !(a == (7 - b));
}

void makeDieRoll(int &a, int &b)
{
}