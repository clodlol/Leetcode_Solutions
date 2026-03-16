#include <iostream>
#include <vector>
using namespace std;

class Fancy
{
    vector<size_t> sequence;
    const int MOD = 1e9 + 7;

public:
    Fancy() {}

    void append(int val) { sequence.push_back(val); }

    void addAll(int inc)
    {
        for (auto &i : sequence)
            i += inc;
    }

    void multAll(int m)
    {
        for (auto &i : sequence)
            i *= m;
    }

    int getIndex(int idx)
    {
        if (idx >= sequence.size())
            return -1;

        return sequence.at(idx) % MOD;
    }
};