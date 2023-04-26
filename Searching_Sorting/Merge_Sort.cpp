#include<bits/stdc++.h>

using namespace std;

// Merge Sort
/* The Merge Sort algorithm is a sorting algorithm 
 * that is based on the Divide and Conquer paradigm. 
 * In this algorithm, the array is initially divided 
 * into two equal halves and then they are combined 
 * in a sorted manner.
 */ 

//O(m+n) with extra space (m+n)
void MergeNaieve(int arr[], int l, int m, int h)
{
    int l1 = l;
    int h1 = m;
    int l2 = m+1;
    int h2 = h;

    int tempArr[h-l+1];
    int i =0;

    while(l1 <= h1 && l2 <= h2)
    {
        if(arr[l1] < arr[l2])
        {
            tempArr[i++] = arr[l1++];
        }
        else
        {
            tempArr[i++] = arr[l2++];
        }
    }

    while(l1 <= h1)
    {
        tempArr[i++] = arr[l1++];
    }

    while(l2 <= h2)
    {
        tempArr[i++] = arr[l2++];
    }

    for(int i = l; i <= h; i++)
    {
        arr[i] = tempArr[i-l];
    }
}

//O(m+n) 
void MergeNaieveOptimized(int arr[], int l, int m, int h, int maxEle)
{
    int l1 = l;
    int h1 = m;
    int l2 = m+1;
    int h2 = h;

    int i = l;

    while(l1 <= h1 && l2 <= h2)
    {
        if((arr[l1]%maxEle) < (arr[l2]%maxEle))
        {
            arr[i++] += (arr[l1++]%maxEle)*maxEle;
        }
        else
        {
            arr[i++] += (arr[l2++]%maxEle)*maxEle;
        }
    }

    while(l1 <= h1)
    {
        arr[i++] += (arr[l1++]%maxEle)*maxEle;
    }

    while(l2 <= h2)
    {
        arr[i++] += (arr[l2++]%maxEle)*maxEle;
    }

    for(int j = l; j <= h; j++)
    {
        arr[j] /= maxEle;
    }
}

void MergeSort(int arr[], int l, int h, int maxEle = 0)
{
    if(l>=h)
        return;

    int mid = l+(h-l)/2;

    MergeSort(arr,l,mid,maxEle);
    MergeSort(arr,mid+1,h,maxEle);
    MergeNaieveOptimized(arr,l,mid,h,maxEle);
}

void mergeSort(int arr[], int n)
{
    int l = 0, h = n-1;
    int m = *max_element(arr,arr+n) + 1;
    MergeSort(arr,l,h,m);
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}