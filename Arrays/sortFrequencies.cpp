#include <iostream>
using namespace std;

/*
    this program takes an array and sorts the elements according to DESCENDING frequencies

    in case two or more adjacent elements have the same frequencies, they're sorted in ascending order
*/

int findMaxIndex(int arr[], int n);
void removeElementAtIndex(int arr[], int &n, int targetIndex); // subtracts 1 from n
void adjustFreqDistinctArrays(int freq[], int distinct[], int n);
void swap(int &a, int &b);

int main()
{
    constexpr int n = 9;
    int arr[n] = {2, 3, 7, 3, 5, 9, 7, 3, 5};
    bool counted[n] = {false};
    int freq[n] = {0};
    int freqCounter = 0;
    int distnctArr[n] = {0};
    int distinctCounter = 0;

    for (int i = 0; i < n; i++)
    {
        if (counted[i])
            continue;

        distnctArr[distinctCounter++] = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
                counted[j] = true;
            }
        }

        freq[freqCounter++] = count;
    }

    adjustFreqDistinctArrays(freq, distnctArr, freqCounter);

    for (int i = 0; i < n;)
    {
        int maxIndex = findMaxIndex(freq, freqCounter);

        int currentElement = distnctArr[maxIndex];
        int currentFrequency = freq[maxIndex];

        for (int j = 0; j < currentFrequency; j++)
        {
            arr[i++] = currentElement;
        }

        removeElementAtIndex(freq, freqCounter, maxIndex);           // caution: freqCounter decreases in this function
        removeElementAtIndex(distnctArr, distinctCounter, maxIndex); // caution: distinctCounter decreases in this function
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}

int findMaxIndex(int arr[], int n)
{
    int largestIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largestIndex])
        {
            largestIndex = i;
        }
    }

    return largestIndex;
}

void removeElementAtIndex(int arr[], int &n, int targetIndex)
{
    for (int i = 0; i < n; i++)
    {
        if (i < targetIndex)
        {
            arr[i] = arr[i];
        }
        else if (i > targetIndex)
        {
            arr[i - 1] = arr[i];
        }
    }

    n--;
}

void adjustFreqDistinctArrays(int freq[], int distinct[], int n)
{
    // make sure n is same for both arrays! our implementation ensures this

    bool sorted = false;
    do
    {
        sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (freq[i] == freq[i + 1])
            {
                if (distinct[i] > distinct[i + 1])
                {
                    swap(distinct[i], distinct[i + 1]);
                    sorted = false;
                }
            }
        }
    } while (!sorted);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}