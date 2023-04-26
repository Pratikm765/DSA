#include<bits/stdc++.h>

using namespace std;

// Binary Search
/* Given a sorted array arr[] of n elements, 
 * write a function to search a given element x 
 * in arr[] and return the index of x in the array.
 */

int BinarySearchIterative(int arr[], int n, int k)
{
    int l = 0, h = n-1;
    while(l < h)
    {
        int mid = l+(h-l)/2;
        if(arr[mid] == k)
        {
            return mid;
        }
        else if(arr[mid] < k)
        {
            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }
    return -1;
}

int BinarySearchRecursive(int arr[], int l, int h, int k)
{
    if(l > h)
        return -1;
    
    int mid = l+(h-l)/2;

    if(arr[mid] == k)
        return mid;

    if(arr[mid] < k)
        return BinarySearchRecursive(arr,mid+1,h,k);
    else
        return BinarySearchRecursive(arr,l,mid-1,k);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int found = BinarySearchIterative(arr,8,60);

    if(found == -1)
        cout << "Not present\n";
    else
        cout << "Present at position " << found << endl;

    found = BinarySearchRecursive(arr,0,7,60);

    if(found == -1)
        cout << "Not present\n";
    else
        cout << "Present at position " << found << endl;

    return 0;
}