#include<bits/stdc++.h>

using namespace std;

// Search Pair with given Sum 
/* Write a program that, given an array A[] of n numbers and 
 * another number x, determines whether or not there exist two 
 * elements in A[] whose sum is exactly x. 
 */

pair<int,int> PairSum(int arr[], int n, int k)
{
    pair<int,int> pr = {0,0};
    int l = 0, h = n-1;

    while(l < h)
    {
        if(arr[l]+arr[h] == k)
        {
            pr.first = l;
            pr.second = h;
            // cout << pr.first << " " << pr.second << endl;
            // count++;
            // l++; h--;
            break;
        }
        else if(arr[l]+arr[h] > k)
        {
            h--;
        }
        else
        {
            l++;
        }

    }
    return pr;
}

pair<int,int> PairSumHashing(int arr[], int n, int k)
{
    pair<int,int> pr = {0,0};
    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++)
    {
        if(mp.find(k-arr[i]) != mp.end())
        {
            pr.first = mp[k-arr[i]];
            pr.second = i;
        }
        mp[arr[i]] = i;
    }
    return pr;
}

int main()
{
    int arr[] = {-3,-1, 0, 1, 2};
    int x = -2;
    int size = sizeof(arr) / sizeof(arr[0]);
    auto it = PairSum(arr,size,x);
    cout << it.first << " " << it.second <<endl;


    int arr1[] =  {10, 22, 28, 29, 30, 40};
    x = 52;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    it = PairSumHashing(arr1,n,x);
    cout << it.first << " " << it.second << endl;

    return 0;
}