#include<bits/stdc++.h>

using namespace std;

// Rearrange array
/* Given an array arr[] of size n where every 
 * element is in range from 0 to n-1. Rearrange 
 * the given array so that arr[i] becomes arr[arr[i]]. 
 * This should be done with O(1) extra space4
 */

void rearrange(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]]%n)*n;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 2, 0, 1}; // 1 0 3 2
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArr(arr, n);
 
    rearrange(arr, n);
 
    cout << "Modified array is \n";
    printArr(arr, n);
    return 0;
}