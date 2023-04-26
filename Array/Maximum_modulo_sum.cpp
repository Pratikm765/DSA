#include<bits/stdc++.h>

using namespace std;

// Maximum subarray sum modulo m
/* Given an array of n elements and an integer m. 
 * The task is to find the maximum value of the 
 * sum of its subarray modulo m i.e find the sum 
 * of each subarray mod m and print the maximum 
 * value of this modulo operation.
 * 
 * Let prefix sum for index i be prefixi, i.e., 
 * prefixi = (arr[0] + arr[1] + .... arr[i] ) % m
 * 
 * Let maximum sum ending with i be, maxSumi. 
 * Let this sum begins with index j.
 * maxSumi = (prefixi - prefixj + m) % m
 * 
 * From above expression it is clear that the
 * value of maxSumi becomes maximum when 
 * prefixj is greater than prefixi 
 * and closest to prefixi
 * 
 * It should be greater and close as much as possible 
 * that will result into less deduction from m from above.
 */



int maxSubarray(int arr[], int n, int m)
{
    set<int> prefixSum;
    prefixSum.insert(0);
    int sum = 0;
    int maxSum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = (sum+arr[i])%m;
        maxSum = max(maxSum,sum);
        auto it = prefixSum.lower_bound(sum+1);

        if(it != prefixSum.end())
        {
            maxSum = max(maxSum,sum-(*it)+m);
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = { 3, 3, 9, 9, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 7;
    cout << maxSubarray(arr, n, m) << endl;
    return 0;
}