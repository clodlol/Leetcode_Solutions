#include <iostream>
#include <vector>
using namespace std;

vector<int> remove(const vector<int> &list, const int &index)
{
    vector<int> t;
    for (int i = 0; i < list.size(); ++i)
    {
        t.push_back(list.at(i));
    }
    t.erase(t.begin() + index);

    return t;
}

void printPermutations(const vector<int> &list)
{
    if (list.size() == 1)
    {
        cout << list.at(0) << " ";
        return;
    }

    for (int i = 0; i < list.size(); ++i)
    {
        cout << list.at(i) << " ";
        printPermutations(remove(list, i));
        cout << "\n";
    }
}

int main()
{
    vector<int> list = {1, 2, 3, 4};
    printPermutations(list);
    return 0;
}