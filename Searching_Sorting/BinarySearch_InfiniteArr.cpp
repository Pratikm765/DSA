#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int arr[], int l, int h, int k)
{
    if(l > h)
        return -1;
    
    int mid = l+(h-l)/2;

    if(arr[mid] == k)
        return mid+1;

    if(arr[mid] < k)
        return BinarySearch(arr,mid+1,h,k);
    else
        return BinarySearch(arr,l,mid-1,k);
}

int BinarySearchInfiniteArr(int arr[], int k)
{
    int l = 0, h = 1;

    while(true)
    {
        if(k <= arr[h])
        {
            return BinarySearch(arr,l,h,k);
        }
        else
        {
            l = h;
            h = 2*h;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 3, 4, 5, 7,
                  8,11,13,14,15,
                 17,18,20,21,23,
                 25,26,27,28,29,
                 31,32,33,37,39,
                 40,44,46,48,49};

    cout << " Position: " << BinarySearchInfiniteArr(arr,37);
    return 0;
}