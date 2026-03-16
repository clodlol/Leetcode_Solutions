#include <iostream>
#include <vector>
using namespace std;

void storeSum(vector<int> &sums, const int &currSum)
{
    bool dupe = false;
    for (const int &i : sums)
    {
        if (i == currSum)
        {
            dupe = true;
            break;
        }
    }

    if (!dupe)
    {
        sums.push_back(currSum);
    }
}

void sort(vector<int> &sums)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < sums.size() - 1; ++i)
        {
            if (sums.at(i) > sums.at(i + 1))
            {
                swap(sums.at(i), sums.at(i + 1));
                sorted = false;
            }
        }
    }
}

int calculateCurrentRhombusSum(const vector<vector<int>> &grid, const int &top, const int &left, const int &bottom, const int &right, const int &i, const int &j)
{
    int sum = 0;
    for (int r = top; r <= i; ++r)
    {
        for (int c = j; c >= left; --c)
        {
            if ((r - top) + (c - left) == j - left) // relative position of r from top and c from left equals j from left satisfying condition i+j==n-1 in this nxn submatrix :sob:
            {
                // cout << grid.at(r).at(c) << " ";
                sum += grid.at(r).at(c);
            }
        }
    }
    for (int r = i + 1; r <= bottom; ++r)
    {
        for (int c = left + 1; c <= j; ++c)
        {
            if ((r - i + 1) == (c - left + 1))
            {
                // cout << grid.at(r).at(c) << " ";
                sum += grid.at(r).at(c);
            }
        }
    }
    for (int r = bottom - 1; r >= i; --r)
    {
        for (int c = j + 1; c <= right; ++c)
        {
            if ((r - i) + (c - j + 1) == right - j + 1)
            {
                // cout << grid.at(r).at(c) << " ";
                sum += grid.at(r).at(c);
            }
        }
    }
    for (int r = i - 1; r > top; --r)
    {
        for (int c = right - 1; c > j; --c)
        {
            if ((c - j + 1) == (r - top + 1))
            {
                // cout << grid.at(r).at(c) << " ";
                sum += grid.at(r).at(c);
            }
        }
    }

    return sum;
}

void calculateRhombusSum(const vector<vector<int>> &grid, const int &i, const int &j, vector<int> &sums) // Print all possible rombuses around (i, j)
{
    const int totalRows = grid.size();
    const int totalCols = grid.at(0).size();

    int du = i, dl = j, dr = j, dd = i;
    while (du >= 0 && dl >= 0 && dr < totalCols && dd < totalRows)
    {
        // cout << "(" << i << ", " << j << ") : " << (i - du) << " : " << "[" << grid.at(du).at(j) << ", " << grid.at(i).at(dl) << ", " << grid.at(dd).at(j) << ", " << grid.at(i).at(dr) << "]" << "\n";

        int curr = calculateCurrentRhombusSum(grid, du, dl, dd, dr, i, j);
        storeSum(sums, curr);
        // cout << "\n";

        du--;
        dl--;
        dr++;
        dd++;
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3, 4, 5, 6, 7},
                                {4, 5, 6, 7, 8, 9, 0},
                                {7, 8, 9, 0, 1, 2, 3},
                                {0, 1, 2, 3, 4, 5, 6},
                                {5, 6, 7, 8, 9, 0, 1},
                                {1, 2, 3, 4, 5, 6, 7},
                                {8, 9, 0, 1, 2, 3, 4}};
    vector<int> sums;
    vector<int> ans;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.at(0).size(); ++j)
        {
            calculateRhombusSum(grid, i, j, sums);
        }
    }

    sort(sums);

    for (int i = sums.size() - 1; i > sums.size() - 4; --i)
    {
        ans.push_back(sums.at(i));
    }

    for (auto &i : ans)
        cout << i << " ";

    return 0;
}