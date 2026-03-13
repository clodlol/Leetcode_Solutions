#include <iostream>
using namespace std;

string invert(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }

        else if (s[i] == '1')
        {
            s[i] = '0';
        }
    }

    return s;
}

string reverse(string s)
{
    for (int i = 0; i <= (s.size() / 2); i++)
        swap(s[i], s[s.size() - 1 - i]);
    return s;
}

string getNthString(const int &n)
{
    if (n == 1)
    {
        return "0";
    }

    return (getNthString(n - 1) + "1" + reverse(invert(getNthString(n - 1))));
}

int main()
{
    cout << getNthString(20) << endl;
    return 0;
}