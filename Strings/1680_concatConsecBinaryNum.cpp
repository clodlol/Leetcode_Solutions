#include <iostream>
#include <string>
using namespace std;

/*
    class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;

        long long result = 0;
        int bitLength = 0;  // Tracks current bit length

        for (int i = 1; i <= n; i++) {

            // If i is power of 2, increase bit length
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }

            // Shift result left by bitLength and add i
            result = ((result << bitLength) | i) % MOD;
        }

        return result;
    }
};
*/

int charToInt(const char &c)
{
    return (c - '0');
}

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void reverseSubstring(string &s, const int &start, const int &end)
{
    for (int i = start; i <= end / 2; i++)
    {
        swap(s[i], s[end - i]);
    }
}

string calculateBinary(int n)
{
    string s;
    int i = n;
    for (; i >= 2; i /= 2)
    {
        s += ('0' + (i % 2));
    }
    s += ('0' + (i));
    reverseSubstring(s, 0, (s.size() - 1));
    return s;
}

string concatenatedBinary(int n)
{
    string s;
    for (int i = 1; i <= n; i++)
    {
        s += calculateBinary(i);
    }
    return s;
}

long long binaryToDec(const string &bin)
{
    long long num = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        num += (charToInt(bin[i])) * pow(2, (bin.size() - 1 - i));
    }
    return num;
}

int calculateAns(const long long &bin)
{
    return (bin % (1000000000 + 7));
}

int main()
{
    cout << calculateAns(binaryToDec(concatenatedBinary(15))) << endl;
    return 0;
}