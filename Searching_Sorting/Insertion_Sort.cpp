#include<bits/stdc++.h>

using namespace std;

// Insertion Sort
/* Insertion sort is a simple sorting algorithm that 
 * works similar to the way you sort playing cards in 
 * your hands. The array is virtually split into a sorted 
 * and an unsorted part. Values from the unsorted part are 
 * picked and placed at the correct position in the 
 * sorted part.
 */

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(arr[j] > key && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}