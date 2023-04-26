#include<bits/stdc++.h>

using namespace std;

// Selection Sort
/* The selection sort algorithm sorts an array by repeatedly 
 * finding the minimum element (considering ascending order) 
 * from unsorted part and putting it at the beginning.
 */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i],arr[min_index]);
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
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}