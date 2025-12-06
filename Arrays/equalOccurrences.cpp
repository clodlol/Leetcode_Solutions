#include <iostream>
using namespace std;

/*
    This program takes an array and checks if it is balanced.
    If it is balanced, it returns the length of the balanced subarray.
    If it is not balanced, it returns the minimum number of moves(along with length of balanced subarray) to make it balanced.
*/

int findMin(int freqArr[], int freqArrSize);

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
        int leastOccurring = findMin(freqArray, freqCounter);
        for (int i = 0; i < freqCounter; i++)
        {
            if (freqArray[i] > leastOccurring)
            {
                k += (freqArray[i] - leastOccurring);
            }
        }
    }

    cout << "The value of k is " << k << endl;
    cout << "The length of balanced subarray is: " << n - k << endl;

    cout << endl;
    system("pause");
    return 0;
}

int findMin(int freqArr[], int freqArrSize)
{
    int smallest = INT_MAX;
    for (int i = 0; i < freqArrSize; i++)
    {
        if (freqArr[i] < smallest)
        {
            smallest = freqArr[i];
        }
    }

    return smallest;
}