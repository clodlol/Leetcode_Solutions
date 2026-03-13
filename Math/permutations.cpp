#include <iostream>
using namespace std;

const char *getBaseString(int n)
{
    string s;
    for (int i = 1; i <= n; i++)
        s += ('0' + i); // for now, assume n is from 1-9
    return (s.c_str());
}

char **permutations(int n)
{
    const char *baseString = getBaseString(n);
}