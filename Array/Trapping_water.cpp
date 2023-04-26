#include<bits/stdc++.h>

using namespace std;

// Trapping Water
/* Given an array of N non-negative integers arr[] 
 * representing an elevation map where the width of 
 * each bar is 1, compute how much water it is able 
 * to trap after raining.
 */

int TrappedWater(int arr[], int n)
{
    int larr[n];
    int rarr[n];
    int water = 0;
    larr[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        larr[i] = max(arr[i],larr[i-1]);
    }

    rarr[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        rarr[i] = max(arr[i],rarr[i+1]);
    }

    for(int i=1; i<n-1; i++)
    {
        int diff = min(larr[i-1],rarr[i+1]);
        if(diff > arr[i])
        water +=  diff - arr[i];
    }
    return water;
}

int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << TrappedWater(arr,n);
    return 0;
}