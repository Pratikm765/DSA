#include<bits/stdc++.h>

using namespace std;

// Peak Element
/* Given an array of integers. Find a peak element 
 * in it. An array element is a peak if it is NOT 
 * smaller than its neighbours. For corner elements, 
 * we need to consider only one neighbour. 
 */

int findPeak(int arr[], int l, int h, int n)
{
    if(l>h)
        return -1;
    int mid = l+(h-l)/2;

    if((mid == 0 || arr[mid] >= arr[mid-1]) &&
       (mid == n-1 || arr[mid] >= arr[mid+1]))
    {
        return mid+1;
    }
    else if((mid != 0) && (arr[mid-1] > arr[mid]))
    {
        return findPeak(arr,l,mid-1,n);
    }
    else
    {
        return findPeak(arr,mid+1,h,n);
    }
}

int main()
{
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is " << findPeak(arr, 0,n-1, n);
    return 0;
}