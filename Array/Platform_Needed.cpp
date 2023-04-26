#include<bits/stdc++.h>

using namespace std;

/* Given the arrival and departure times of all 
 * trains that reach a railway station, the task 
 * is to find the minimum number of platforms 
 * required for the railway station so that no 
 * train waits. We are given two arrays that 
 * represent the arrival and departure times of 
 * trains that stop.
 */

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int platforms = 1;
    int Curr = 1;
    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            Curr++;
            i++;
        }
        else
        {
            Curr--;
            j++;
        }

        platforms = max(platforms,Curr);
    }
    return platforms;
}

int main()
{
    // Train 1 => Arrival : 01:00, Departure : 09:00
    // Train 2 => Arrival : 03:00, Departure : 04:00
    // Train 3 => Arrival : 05:00, Departure : 06:00
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", findPlatform(arr, dep, n));
    return 0;
}