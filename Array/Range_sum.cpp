#include<bits/stdc++.h>

using namespace std;

// Range sum using prefix sum technique

int prefixSumTechnique(int arr[], int n, int i, int j)
{
    int prefixSumArr[n];
    prefixSumArr[0] = arr[0];
    for(int i=1; i < n; i++)
    {
        prefixSumArr[i] = prefixSumArr[i-1] + arr[i];
    }

    return i?prefixSumArr[j]-prefixSumArr[i-1]: prefixSumArr[j];
}

int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 1 };
    int start = 2;
    int end = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << prefixSumTechnique(arr, size, start,end);
    return 0;
}