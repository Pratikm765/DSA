#include<bits/stdc++.h>

using namespace std;

// Three way QuickSort
/* In 3 Way QuickSort, an array arr[l..r] is divided in 3 parts:
 * a) arr[l..i] elements less than pivot.
 * b) arr[i+1..j-1] elements equal to pivot.
 * c) arr[j..r] elements greater than pivot.
 */
void  partition(int arr[], int l, int h, int& i, int& j)
{
    i = l-1;
    j = h;
    int p = l-1;
    int q = h;
    int pivot = arr[h];

    while(i < j)
    {
        while(arr[++i] < pivot)
            ;

        while(arr[--j] > pivot)
        {
            if(j == l)
                break;
        }

        if(i >= j)
            break;

        swap(arr[i],arr[j]);

        if(arr[i] == pivot)
        {
            p++;
            swap(arr[i],arr[p]);
        }

        if(arr[j] == pivot)
        {
            q--;
            swap(arr[j],arr[q]);
        }
    }

    swap(arr[i],arr[h]);

    j = i-1;
    for(int m = l; m <= p; m++ , j--)
    {
        swap(arr[m],arr[j]);
    }

    i = i+1;
    for(int m = h-1; m >= q; m--,i++)
    {
        swap(arr[m],arr[i]);
    } 
}

void QuickSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int i,j;
        partition(arr,l,h,i,j);
        QuickSort(arr,l,j);
        QuickSort(arr,i,h);
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