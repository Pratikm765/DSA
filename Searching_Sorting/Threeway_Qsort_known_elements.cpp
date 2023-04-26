#include<bits/stdc++.h>

using namespace std;

void QuickSort(int arr[], int l, int r)
{
    int m = l;
    while(m < r)
    {
        switch(arr[m])
        {
            case 1:
            {
                swap(arr[l++],arr[m++]);
                break;
            }
            case 4:
            {
                m++;
                break;
            }
            case 9:
            {
                swap(arr[m],arr[r--]);
                break;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 9 };
    int size = sizeof(a) / sizeof(int);
    printArray(a, size);
    QuickSort(a, 0, size - 1);
    printArray(a, size);
    return 0;
}