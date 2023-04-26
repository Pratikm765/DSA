#include<bits/stdc++.h>

using namespace std;

// Count Occurences Binary Search
/* Given a sorted array arr[] of n elements, 
 * write a function to search a given element x 
 * in arr[] and return the total count of occurences
 * in the array.
 */

int LeftMostOccurence(int arr[], int l, int h, int k)
{
    if(l>h)
        return -1;

    int mid = l+(h-l)/2;

    if((arr[mid] == k) && 
       (mid == 0 || arr[mid] != arr[mid-1]))
       {
           return mid+1;
       }

    if(arr[mid] >= k)
    {
        return LeftMostOccurence(arr,l,mid-1,k);
    }
    else
    {
        return LeftMostOccurence(arr,mid+1,h,k);
    }
}

int RightMostOccurence(int arr[], int l, int h, int n, int k)
{
    if(l>h)
        return -1;

    int mid = l+(h-l)/2;

    if((arr[mid] == k) && 
       (mid == n || arr[mid] != arr[mid+1]))
       {
           return mid+1;
       }

    if(arr[mid] > k)
    {
        return RightMostOccurence(arr,l,mid-1,n,k);
    }
    else
    {
        return RightMostOccurence(arr,mid+1,h,n,k);
    }
}

int main()
{
    int arr[] = {1,2,2,2,3,4,4,5,5,5,5,6};
    cout << "Total Count: " << RightMostOccurence(arr,0,11,11,5) - LeftMostOccurence(arr,0,11,5) + 1;
    return 0;
}