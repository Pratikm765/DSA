#include<bits/stdc++.h>

using namespace std;

int immediateSmaller(int arr[], int n, int x)
{
    int result = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < x)
        {
            result = max(result,arr[i]);
        }
    }
    return result;
}

int main()
{

    return 0;
}