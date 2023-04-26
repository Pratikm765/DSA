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

void ReverseArray1(int arr[], int n)
{
    printArr(arr,n);
    int i = 0;
    int j = n-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    printArr(arr,n);
}

void ReverseArray(int arr[], int n)
{
    printArr(arr,n);
    stack<int> st;
    
    int i = 0;
    while(i<n)
    {
        st.push(arr[i]);
        i++;
    }

    i = 0;
    while(!st.empty())
    {
        arr[i++]=st.top();
        st.pop();
    }
    printArr(arr,n);
}

int main()
{
    int arr[5]={10,45,33,48,62};
    ReverseArray(arr, 5);
    return 0;
}