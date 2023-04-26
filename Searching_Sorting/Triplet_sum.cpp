#include<bits/stdc++.h>

using namespace std;

// Triplet Sum
/* Given an array and a value, find if there is a triplet in 
 * array whose sum is equal to the given value. If there is 
 * such a triplet present in array, then print the triplet 
 * and return true. Else return false.
 */
void findTriplet(int arr[], int n, int t)
{
    for(int i = 0; i < n-2; i++)
    {
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            if(arr[i]+arr[j]+arr[k] == t)
            {
                cout << i << " " << j << " " << k << endl;
                break;
            }
            else if(arr[i]+arr[j]+arr[k] > t)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int A[] = { 1, 4, 6, 8, 10, 45 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    findTriplet(A, arr_size, sum);
    return 0;
}