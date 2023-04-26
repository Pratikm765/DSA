#include<bits/stdc++.h>

using namespace std;

// Sorted Rotated Array Binary search
/* Given a sorted and rotated array arr[] 
 * of size N and a key, the task is to find 
 * the key in the array.
 */
int BinarySearch_SRArray(int arr[], int l, int h, int k)
{
    if(l>h)
        return -1;

    int mid = l+(h-l)/2;

    if(arr[mid] == k)
        return mid+1;

    // to handle duplicates
    // 3 1 2 3 3 3 3
    // 3 3 3 3 1 2 3
	if ((arr[l] == arr[mid]) && (arr[h] == arr[mid]))
	{
	    ++l;
	    --h;
	}

    if(arr[l] <= arr[mid])
    {
        if(arr[l] <= k && k < arr[mid])
            return BinarySearch_SRArray(arr,l,mid-1,k);
        else
            return BinarySearch_SRArray(arr,mid+1,h,k);
    }
    else
    {
        if(arr[mid] < k && k <= arr[h])
            return BinarySearch_SRArray(arr,mid+1,h,k);
        else
            return BinarySearch_SRArray(arr,l,mid-1,k);
    }
    return -1;
}

int main()
{
    int arr[] = {5,6,7,1,2,3,4};
    cout << "Position: " << BinarySearch_SRArray(arr,0,6,6);
    return 0;
}