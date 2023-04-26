#include<bits/stdc++.h>

using namespace std;

int maxFreqNumberNaieve(int left[], int right[],int n)
{
    int arr[100] = {0};
    int maxim = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = left[i]; j <= right[i]; j++)
        {
            arr[j]++;
        }
        maxim = max(right[i],maxim);
    }

    int result = 0;
    int maxFreq = 0;
    for(int i = 0; i < maxim; i++)
    {
        if(result < arr[i])
        {
            result = max(result,arr[i]);
            maxFreq = i;
        }
        
    }

    return maxFreq;

}
int maxFreqNumber(int left[], int right[],int n)
{
    int arr[100] = {0};
    int maxim = 0;
    for(int i = 0; i < n; i++)
    {
        arr[left[i]]++;
        arr[right[i]]--;
        maxim = max(right[i],maxim);
    }

    int result = 0;
    int maxFreq = 0;
    int prefixSum = 0;
    for(int i = 0; i <= maxim; i++)
    {
        prefixSum += arr[i];
        if(result < prefixSum)
        {
            result = max(result,prefixSum);
            maxFreq = i;
        }
    }

    return maxFreq;

}
int main()
{
    int L[] = { 1, 4, 6, 13, 14 };
    int R[] = { 15, 8, 12, 20, 30 };
    int n = sizeof(L) / sizeof(L[0]);

    cout << maxFreqNumber(L, R, n) << endl;
    return 0;
}