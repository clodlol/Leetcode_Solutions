#include <iostream>
using namespace std;

void invert(char &c)
{
    if (c == '0')
    {
        c = '1';
    }
    else
    {
        c = '0';
    }
}

int transformString(string s, int startChoice)
{
    int c = 0, len = s.size();
    if (startChoice == 0)
    {
        if (s[0] != '0')
        {
            invert(s[0]);
            c++;
        }
    }
    else if (startChoice == 1)
    {
        if (s[0] != '1')
        {
            invert(s[0]);
            c++;
        }
    }

    char currentState = s[0] == '0' ? '1' : '0';
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != currentState)
        {
            invert(s[i]);
            c++;
        }

        currentState = currentState == '0' ? '1' : '0';
    }

    return c;
}

int main()
{
    string s = "10010100";
    cout << min(transformString(s, 0), transformString(s, 1)) << "\n";

    return 0;
}