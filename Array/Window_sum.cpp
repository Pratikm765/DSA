#include<bits/stdc++.h>

using namespace std;

// Window sum

int windowSum(int arr[], int n, int k)
{
    int maxSum = 0;
    int currSum = 0;
    for(int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }

    for(int i=k; i < n; i++)
    {
        currSum += arr[i] - arr[i-k];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << windowSum(arr,n,k); 
    return 0;
}