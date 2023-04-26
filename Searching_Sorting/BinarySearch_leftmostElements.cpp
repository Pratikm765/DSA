#include<bits/stdc++.h>

using namespace std;

// Leftmost Occurence Binary Search
/* Given a sorted array arr[] of n elements, 
 * write a function to search a given element x 
 * in arr[] and return the index of its first occurence
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

int main()
{
    int arr[] = {1,2,2,2,3,4,4,5,5,5,5,6};
    cout << "Position: " << LeftMostOccurence(arr,0,11,5);
    return 0;
}