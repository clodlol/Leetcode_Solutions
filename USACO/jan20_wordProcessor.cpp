#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");

    int n, k;
    fin >> n >> k;

    vector<string> words;
    for (int i{0}; i < n; ++i)
    {
        string w;
        fin >> w;
        words.push_back(w);
    }

    int letterTracker = 0;
    for (const string &s : words)
    {
        if ((letterTracker + s.size()) > k)
        {
            fout << "\n";
            letterTracker = 0;
        }
        fout << s << " ";
        letterTracker += s.size();
    }

    return 0;
}