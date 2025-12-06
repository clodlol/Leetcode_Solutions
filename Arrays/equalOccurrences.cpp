#include <iostream>
using namespace std;

/*
    This program takes an array and checks if it is balanced.
    If it is balanced, it returns the length of the balanced subarray.
    If it is not balanced, it returns the minimum number of moves(along with length of balanced subarray) to make it balanced.
*/

int findMax(int freqArr[], int freqArrSize);

int main()
{
    constexpr int n = 5;
    int arr[n] = {3, 3, 3, 3, 3};
    bool balanced = true;
    int k = 0; // number of moves to make equal occurrences

    int freqArray[n] = {0}; // non duplicate frequency array
    int freqCounter = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < (i == (n - 1) ? INT_MAX : arr[i + 1]))
        {
            count++;
            freqArray[freqCounter++] = count;

            count = 0;
        }
        else
        {
            count++;
        }
    }

    for (int i = 0; i < freqCounter; i++)
    {
        if (freqArray[i] != freqArray[0])
        {
            balanced = false;
            break;
        }
    }

    if (!balanced)
    {
        int maxLen = 0;
        for (int target = 1; target <= findMax(freqArray, freqCounter); target++)
        {
            for (int i = 0; i < freqCounter; i++)
            {
                int count = 0;
                if (freqArray[i] >= target)
                {
                    count++;
                }

                if ((count * target) > maxLen)
                {
                    maxLen = (count * target);
                }
            }
        }

        cout << "The length of balanced subarray is: " << maxLen << endl;
    }
    else
    {
        cout << "The length of balanced subarray is: " << n << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}

int findMax(int freqArr[], int freqArrSize)
{
    int largest = INT_MIN;
    for (int i = 0; i < freqArrSize; i++)
    {
        if (freqArr[i] > largest)
        {
            largest = freqArr[i];
        }
    }

    return largest;
}