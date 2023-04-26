#include<bits/stdc++.h>

using namespace std;

/* Bubble Sort is the simplest sorting algorithm that works 
 * by repeatedly swapping the adjacent elements if they are 
 * in the wrong order. This algorithm is not suitable for 
 * large data sets as its average and worst-case time complexity 
 * is quite high.
 */

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}