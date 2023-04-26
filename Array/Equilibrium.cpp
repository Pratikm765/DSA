#include<bits/stdc++.h>

using namespace std;

/* Equilibrium index of an array is an index such 
 * that the sum of elements at lower indexes is 
 * equal to the sum of elements at higher indexes
 */

int findEquilibrium(int arr[], int n)
{
    int lsum = 0;
    int rsum = 0;

    for(int i = 0; i < n; i++)
    {
        rsum += arr[i];
    }

    for(int i=0; i < n; i++)
    {
        rsum -= arr[i];

        if(lsum == rsum)
            return i;

        lsum += arr[i];

    }
    return -1;
}

int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findEquilibrium(arr, size);
    return 0;
}