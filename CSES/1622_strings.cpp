#include <iostream>
#include <vector>
using namespace std;

void storePermutation(const string &s, vector<string> &permutations)
{
    bool dupe = false;
    for (const string &p : permutations)
    {
        if (p == s)
        {
            dupe = true;
            break;
        }
    }

    if (!dupe)
    {
        permutations.push_back(s);
    }
}

void sortLexicographically(string &s)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s.at(i) > s.at(i + 1))
            {
                swap(s.at(i), s.at(i + 1));
                sorted = false;
            }
        }
    }
}

void getPermutations(const int &n, const string &chars, string &prefix, vector<string> &permutations)
{
    if (n == 1)
    {
        for (int i = 0; i < chars.size(); ++i) // O(n^2)
        {
            string res = prefix + chars.at(i);
            storePermutation(res, permutations); // O(n)
        }
        return;
    }

    for (int i = 0; i < chars.size(); ++i)
    {
        string tPrefix = prefix;
        tPrefix += chars.at(i);

        string tChars = chars;
        tChars.erase(tChars.begin() + i); // O(n)

        getPermutations(n - 1, tChars, tPrefix, permutations);
    }
}

int main()
{
    string s, prefix;
    vector<string> permutations;

    cin >> s;

    sortLexicographically(s); // O(n^2)
    getPermutations(s.size(), s, prefix, permutations);

    cout << permutations.size() << "\n";
    for (const string &p : permutations)
    {
        cout << p << "\n";
    }
    return 0;
}