#include<bits/stdc++.h>

using namespace std;

// Quick Sort
/* Like Merge Sort, QuickSort is a Divide and Conquer 
 * algorithm. It picks an element as a pivot and partitions 
 * the given array around the picked pivot such that it placed
 * at position where all previous elements are lesser than pivot
 * and all further elements are greater than pivot.
 */

int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i = l;
    int j = r-1;
    while(i < j)
    {
        while(i < r && arr[i] < pivot)
        {
            i++;
        }
        
        while(j > 0 && arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
            swap(arr[i],arr[j]);

    }
    swap(arr[i],arr[r]);
    return i;
}

int partitionOptimized(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i = l-1;

    for(int j = l; j < r; j++)
    {
        if(pivot > arr[j])
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void QuickSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int p = partition(arr,l,h);
        QuickSort(arr,l,p-1);
        QuickSort(arr,p+1,h);
    }
}

void printArray(int arr[], int n)
{
    cout << endl;
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
    QuickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}