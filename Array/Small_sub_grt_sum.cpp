#include<bits/stdc++.h>

using namespace std;


// Smallest subarray with sum greater than a given value
/* Given an array of integers and a number x, find the 
 * smallest subarray with sum greater than the given value. 
 */

int smallestSubWithSum(int arr[], int n, int x)
{
    int currSum = 0;
    int start = 0;
    int len = n+1;
    for(int end = 0; end  < n; end++)
    {
        currSum += arr[end];

        while(currSum > x)
        {
            int tempLen = end - start + 1; 
            if( len > tempLen)
                len = tempLen;
            currSum -= arr[start];
            start++;

            // if currSum reaches zero it means one element
            // present which is greater than x
            if(currSum == 0)
            {
                len = -1;
                break;
            }
        }
    }
    return len;
}

int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? cout << "Not possible\n" :
                    cout << res1 << endl;
 
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2+1)? cout << "Not possible\n" :
                    cout << res2 << endl;
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3+1)? cout << "Not possible\n" :
                    cout << res3 << endl;
    return 0;
}

