#include<bits/stdc++.h>

using namespace std;

// Median of two Sorted Arrays
/* Given two sorted arrays, a[] and b[], the task is 
 * to find the median of these sorted arrays.
 */
int findMedian(int arr[], int n, int brr[], int m)
{
    if(n > m)
        findMedian(brr, m, arr, n);

    int l = 0;
    int h = n;

    while(l <= h)
    {
        int p1 = (l+h)/2;
        int p2 = (n+m+1)/2-p1;

        int l1 = p1==0 ? INT_MIN : arr[p1-1];
        int r1 = p1==n ? INT_MAX : arr[p1];

        int l2 = p2==0 ? INT_MIN : brr[p2-1];
        int r2 = p2==m ? INT_MAX : brr[p2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n+m)%2 == 0)
            {
                return (max(l1,l2)+min(r1,r2))/2;
            }
            else
            {
                return max(l1,l2);
            }
        }
        else if(l1 > r2)
        {
            h = p1-1;
        }
        else
        {
            l = p1+1;
        }
    }
    return -1;
}
int main()
{
    int ar1[] = {2, 3, 10, 12};
    int ar2[] = {5, 8, 14, 16, 18};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    cout << findMedian(ar1, n1, ar2, n2);
    return 0;
}