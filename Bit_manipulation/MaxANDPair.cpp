#include <bits/stdc++.h>
using namespace std;

int setCount(int pat, int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if((pat & arr[i]) == pat)
            count++;
    }
    return count;
}
 
int maxAND(int arr[], int n)
{
    int res = 0, count;

    for (int i = 31; i >= 0; i--)
    {
        count = setCount(res | (1 << i), arr, n);

        if(count >= 2)
            res = res | (1 << i);
    } 
    return res;
}
 
int main()
{
    int arr[] = { 4, 8, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum AND Value = " << maxAND(arr, n);
    return 0;
}