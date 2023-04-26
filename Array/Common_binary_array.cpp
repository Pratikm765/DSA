#include<bits/stdc++.h>

using namespace std;

// Longest Span with same Sum in two Binary arrays
/* Given two binary arrays, arr1[] and arr2[] 
 * of the same size n. Find the length of the 
 * longest common span (i, j) where j >= i such
 * that arr1[i] + arr1[i+1] + …. + arr1[j] = 
 * arr2[i] + arr2[i+1] + …. + arr2[j].
 */

int longestCommonSum(bool arr1[], bool arr2[], int n)
{
    int prefixSum1 = 0, prefixSum2 = 0;
    int diffArr[2*n+1] = {-1};
    int maxlen = 0;

    for(int i = 0; i < n; i++)
    {
        prefixSum1 += arr1[i];
        prefixSum2 += arr2[i];

        int diff = prefixSum1 -prefixSum2 + n;

        if(diff == 0)
        {
            maxlen = i+1;
        }
        else if(diffArr[diff] == -1)
        {
            diffArr[diff] = i;
        }
        else
        {
            if(maxlen < i-diffArr[diff])
            {
                maxlen = i-diffArr[diff];
            }
        }
    }

    return maxlen;
}

int main()
{
    bool  arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool  arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Length of the longest common span with same "
            "sum is "<< longestCommonSum(arr1, arr2, n);
    return 0;
}