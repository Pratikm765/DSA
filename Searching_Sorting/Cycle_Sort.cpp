#include<bits/stdc++.h>

using namespace std;

// Cycle Sort
/* Cycle sort is an in-place sorting Algorithm, 
 * unstable sorting algorithm, a comparison sort 
 * that is theoretically optimal in terms of the 
 * total number of writes to the original array.
 */

void cycleSort(int arr[], int n)
{
    int swaps = 0;
    for(int i = 0; i < n-1; i++)
    {
        int pos = i;
        int item = arr[i];

        for(int j = i+1; j < n; j++)
        {
            if(item > arr[j])
                pos++;
        }

        if(pos == i)
            continue;

        while(arr[pos]==item)
			pos++;

        if(pos != i)
            swap(arr[pos],item);

        while(pos != i)
        {
            pos = i;

            for(int j = i+1; j < n; j++)
            {
                if(item > arr[j])
                    pos++;
            }

            while(arr[pos]==item)
				pos++;

            if(item != arr[pos])
            {
                swaps++;
                swap(arr[pos],item);
            }

        }
    }
    cout << swaps << endl;
}

int main()
{
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
 
    cout << "After sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}