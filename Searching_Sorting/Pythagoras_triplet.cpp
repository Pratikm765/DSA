#include<bits/stdc++.h>

using namespace std;

// Pythagoras triplet
/* Given an array of integers, write a function that 
 * returns true if there is a triplet (a, b, c) that 
 * satisfies a2 + b2 = c2.
 */

bool isTriplet(int arr[], int n)
{
    for(int k = n-1; k > 1; k--)
    {
        int i = 0;
        int j = k-1;
        int ksq = arr[k]*arr[k];
        while(i < j)
        {
            int isq = arr[i]*arr[i];
            int jsq = arr[j]*arr[j]; 
            if(isq+jsq == ksq)
            {
                cout << i << " " << j << " " << k << endl;
                return true;
            }
            else if(isq+jsq > ksq)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}

int main()
{
    int ar[] = {1,3,4,5,6 };
    int ar_size = sizeof(ar) / sizeof(ar[0]);
    isTriplet(ar, ar_size) ? cout << "Yes" : cout << "No";
    return 0;
}