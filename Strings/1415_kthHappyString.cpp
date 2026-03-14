#include <iostream>
#include <vector>
using namespace std;

const vector<string> allChoices = {"a", "b", "c"};

void excludeChoice(vector<string> &v, const string &choice)
{
    for (int i = 0; i < v.size();)
    {
        if (v.at(i) != choice)
        {
            ++i;
            continue;
        }

        v.erase(v.begin() + i);
    }
}

string getKthHappyString(const int &n, string &prefix, const vector<string> &choices, const int &k, int &counter)
{
    if (n == 1)
    {
        for (int i = 0; i < choices.size(); ++i)
        {
            counter++;
            if (counter == k)
            {
                // cout << prefix << choices.at(i) << "\n";
                return (prefix += choices.at(i));
            }
        }
        return "";
    }

    for (int i = 0; i < choices.size(); ++i)
    {
        string tPrefix = prefix;
        tPrefix += choices.at(i);

        vector<string> tChoices = allChoices;
        excludeChoice(tChoices, choices.at(i));
        string res = getKthHappyString(n - 1, tPrefix, tChoices, k, counter);

        if (!res.empty())
        {
            return res;
        }
    }

    return "";
}

int main()
{
    int counter = 0;
    const int n = 10, k = 100;
    string prefix = "";
    cout << getKthHappyString(n, prefix, allChoices, k, counter);
    return 0;
}