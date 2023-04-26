#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-maximum-subset-xor-given-set/
int maxSubsetXOR(int arr[], int n)
{
    int index = 0;

    for(int i = 31; i >= 0; i--)
    {
        int maxEle = INT_MIN;
        int maxIndex = index;
        for(int j = index; j < n; j++)
        {
            if(((arr[j] & (1 << i)) != 0) &&
               (arr[j] > maxEle))
               {
                   maxEle = arr[j];
                   maxIndex = j;
               }
        }

        if(maxEle == INT_MIN)
            continue;

        swap(arr[index],arr[maxIndex]);

        maxIndex = index;

        for(int j = 0; j < n; j++)
        {
            if((j != maxIndex) &&
               ((arr[j] & (1 << i)) != 0))
               {
                   arr[j] = arr[j] ^ maxEle;
               }
        }
        index++;
    }
    
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}

int main()
{
    int set[] = {9, 8, 5};
    int n = sizeof(set) / sizeof(set[0]);
     
    cout << "Max subset XOR is ";
    cout << maxSubsetXOR(set, n);
    return 0;
}