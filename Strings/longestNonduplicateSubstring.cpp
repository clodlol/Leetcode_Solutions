#include <iostream>
using namespace std;

int main()
{
    string s = "pwwkew";
    int longest = INT_MIN;

    for (int i = 0; i < s.size(); i++)
    {
        char current = s[i];
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] == current)
            {
                if (j - i > longest)
                {
                    longest = j - i;
                }

                break;
            }
        }
    }

    cout << longest << endl;

    system("pause");
    return 0;
}