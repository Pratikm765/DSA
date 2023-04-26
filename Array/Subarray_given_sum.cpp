#include<bits/stdc++.h>

using namespace std;

// subarray with given sum
/* Given an array arr[] of nonnegative integers and 
 * an integer sum, find a continuous subarray which 
 * adds to a given sum.
 */

vector<int> subarraySumOptimized(int arr[], int n, int s)
{
    vector<int> v;
    unordered_map<int,int> sums;
    
    int prefixSum = 0;
    for(int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if(prefixSum == s)
        {
            v.push_back(0);
            v.push_back(i);
            break;
        } 
        else if(sums.find(prefixSum-s) != sums.end())
        {
            v.push_back(sums[prefixSum-s]+1);
            v.push_back(i);
            break;
        }
        sums[prefixSum] = i;
    }
    if(v.empty())
    {
        v.push_back(0);
        v.push_back(-1);
    }
    return v;
}

vector<int> subarraySum(int arr[], int n, int s)
{
    vector<int> v;
    int sum = 0, start = 0;
    
    for(int end = 0; end < n; end++)
    {
        sum += arr[end];

        while(sum > s)
        {
            sum -= arr[start];
            start++;
        }

        if(sum == s)
        {
            v.push_back(start);
            v.push_back(end);
        }
    }

    if(v.empty())
    {
        v.push_back(0);
        v.push_back(-1);
    }
    return v;
}
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    vector<int> v = subarraySum(arr, n, sum);   
    for(int i = v[0]; i <= v[1]; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}