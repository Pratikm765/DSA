#include<bits/stdc++.h>

using namespace std;

// Missing element
/* Given a list of n-1 integers and these integers 
 * are in the range of 1 to n. There are no duplicates 
 * in list. One of the integers is missing in the list. 
 * Write an efficient code to find the missing integer. 
 */

int findMissing(int arr[], int n) 
{
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i+1] != arr[i] + 1)
        {
            return arr[i]+1;
        }
    }
    return -1;
}

int findMissingOptimized(int arr[], int n) 
{
    int a = 0, b = n - 1;
    int mid;
    while ((b - a) > 1) {
        mid = (a + b) / 2;
        if ((arr[a] - a) != (arr[mid] - mid))
            b = mid;
        else if ((arr[b] - b) != (arr[mid] - mid))
            a = mid;
    }
    return (arr[a] + 1);
}


int main()
{
    int arr[] = {1,2,3,4,6,7,8};
    cout << findMissingOptimized(arr,7);
    return 0;
}