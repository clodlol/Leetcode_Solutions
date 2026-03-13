#include <iostream>
using namespace std;

int countMinMaxDifference(int partition[], int n)
{
    int largest = partition[0];
    int smallest = partition[0];

    for (int i = 0; i < n; i++)
    {
        if (partition[i] > largest)
            largest = partition[i];

        if (partition[i] < smallest)
            smallest = partition[i];
    }

    return (largest - smallest);
}

int main()
{
    const int n = 5;
    int arr[n] = {9, 4, 1, 3, 7};
    int k = 4;

    int count = 0;
    for (int i = 0; i < n - 1; i++) // minimum partition size 1, max n-1
    {
        int left = 0, right = left + i;

        while (right <= n - 1)
        {
            int temp[n] = {0};
            int tempCounter = 0;
            for (int j = left; j <= right; j++)
            {
                cout << arr[j];
                temp[tempCounter++] = arr[j];
            }

            int minMaxDifference = countMinMaxDifference(temp, tempCounter);

            cout << "(" << minMaxDifference << ") ";

            if (minMaxDifference <= k)
                count++;

            left++;
            right++;
        }
        cout << endl;
    }

    cout << count << endl;

    system("pause");
    return 0;
}