#include<bits/stdc++.h>

using namespace std;

// Kadane's Algorithm (DP or greedy)
/* Write an efficient program to find the sum 
 * of the contiguous subarray within a 
 * one-dimensional array of numbers that has 
 * the largest sum. 
 */


int maxSubArraySum(int arr[], int n)
{
    int maxSum = arr[0];
    int currSum = arr[0];
    for(int i = 1; i < n; i++)
    {
        currSum = max(arr[i],currSum+arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}