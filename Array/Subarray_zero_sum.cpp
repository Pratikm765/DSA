#include<bits/stdc++.h>

using namespace std;

/* Given an array of positive and negative numbers, 
 * find if there is a subarray (of size at least one) 
 * with 0.
 */

bool subarrayZero(int arr[], int n)
{
    set<int> sums;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if((sum == 0) || 
            (sums.find(sum) != sums.end()))
        return true;

        sums.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    if (subarrayZero(arr, N))
        cout << "Found a subarray with 0 sum\n";
    else
        cout << "No Such Sub Array Exists!\n";

    int arr2[] = {4, 2, -3, 1, 6};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
 
    if (subarrayZero(arr2, N2))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}