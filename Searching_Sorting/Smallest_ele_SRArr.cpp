#include<bits/stdc++.h>

using namespace std;

// Smallest Element in Sorted Rotated Array
/* Given a sorted and rotated array arr[] 
 * of size N, the task is to find 
 * the smallest element in the array.
 */
int smallestElementSRArr(int arr[], int n)
{
    int l = 0, h = n-1;
    while(l <= h)
    {
        int mid = l+(h-l)/2;

        if(arr[mid] == arr[h])
        {
            h--;
        }
        else if(arr[mid] > arr[h])
        {
            l = mid+1;
        }
        else
        {
            h = mid;
        }
    }
    return h+1;
}

int main()
{
    int arr[] = {5,6,7,1,2,3,4};
    cout << "Position: " << smallestElementSRArr(arr,7);
    return 0;
}