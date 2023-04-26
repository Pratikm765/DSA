#include<bits/stdc++.h>

using namespace std;

void printArr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void reverseArray(int arr[],int i, int j)
{
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void RotateArray(int arr[], int n, int k)
{
    printArr(arr,n);
    reverseArray(arr, 0 , k);
    reverseArray(arr, k+1, n-1);
    reverseArray(arr, 0, n-1);
    printArr(arr,n);
}

int main()
{
    int arr1[5]={10,45,33,48,62};
    RotateArray(arr1, 5, 2);
    return 0;
}