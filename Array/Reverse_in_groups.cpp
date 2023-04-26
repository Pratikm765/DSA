#include<bits/stdc++.h>

using namespace std;

void reverseInGroups(int arr[], int n, int k)
{
    int i;
    for(i = 0; i+k-1 < n; i+=k)
    {
        int left = i;
        int right = i+k-1;

        while(left < right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    if(i < n)
    {
        int left = i;
        int right = n-1;

        while(left < right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    reverseInGroups(arr,14,3);
    for(int i = 0; i < 14; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}