#include<bits/stdc++.h>

using namespace std;

void PrintArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

}

//O(m*n) with no extra space
void MergeArr(int arr1[], int m, int arr2[], int n)
{
    for(int i = n-1; i >= 0; i--)
    {
        int last = arr1[m-1];
        int j;
        for(j = m-2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j+1] = arr1[j];
        }

        if(j != m-2 || last > arr2[i])
        {
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}

// O((n+m)log(n+m)) with no extra space
void MergeArrOpt(int arr1[], int m, int arr2[], int n)
{
    int i = 0;
    int j = m-1;
    while(i < n && j >= 0)
    {
        if(arr2[i] < arr1[j])
        {
            swap(arr2[i],arr1[j]);
            i++;
            j--;
        }
        else
            break;
    }

    sort(arr1,arr1+m);
    sort(arr2,arr2+n);
}

//O(m+n) with extra space (m+n)
void MergeNaieve(int arr1[], int m, int arr2[], int n)
{
    int tempArr[m+n];
    int i = 0;
    int l1 = 0;
    int l2 = 0;
    int h1 = m;
    int h2 = n;

    while(l1 < h1 && l2 < h2)
    {
        if(arr1[l1] < arr2[l2])
        {
            tempArr[i++] = arr1[l1++];
        }
        else
        {
            tempArr[i++] = arr2[l2++];
        }
    }

    while(l1 < h1)
    {
        tempArr[i++] = arr1[l1++];
    }

    while(l2 < h2)
    {
        tempArr[i++] = arr2[l2++];
    }

    i = 0;
    for(int j = 0; j < m; j++)
    {
        arr1[j] = tempArr[i++];
    }

    for(int j = 0; j < n; j++)
    {
        arr2[j] = tempArr[i++];
    }
}

void ReverseArr(int arr[], int l, int h)
{
    while(l < h)
    {
        swap(arr[l],arr[h]);
        l++;
        h--;
    }
}

void RotateArr(int arr[], int m, int k)
{
    ReverseArr(arr,0,k-1);
    ReverseArr(arr,k,m-1);
    ReverseArr(arr,0,m-1);
}

// O(min(nlogn, mlogm)) with no extra space
void MergeMoreOpt(int arr1[], int m, int arr2[], int n)
{
    int l = 0, h = m-1, med = 0;

    while(l <= h){
        int c1 = (l+h)/2; // median of arr1
        int c2 = m-c1-1;  // first element of arr2

        int l1 = arr1[c1]; // part of arr1
        int l2 = arr2[c2-1]; // part of arr1

        int r1 = c1 == m-1 ? INT_MAX : arr1[c1+1]; // part of arr2
        int r2 = c2 == n ? INT_MAX : arr2[c2]; // part of arr2

        if(l1 > r2)
        {
            h = c1-1;
            if(h == -1)
                med = 0;
        }
        else if(l2 > r1)
        {
            l = c1+1;
            if(l == m-1)
                med = m;
        }
        else
        {
            med = c1+1;
            break;
        }
    }
    //moved right part in arr1 to arr2
    for(int i=med; i < m; i++)
    {
        swap(arr1[i],arr2[i-med]);
    }
    sort(arr1,arr1+m);
    sort(arr2,arr2+n);
}

void MergeArrMoreOpt(int arr1[], int m, int arr2[], int n)
{
    if( m > n)
    {
        MergeMoreOpt(arr2,n,arr1,m);
        // int ar1[] = { 1, 5, 9, 10, 15, 20 };
        // int ar2[] = { 2, 3, 8, 13 };
        // int ar1[] = { 8, 9, 10, 13, 15, 20 };
        // int ar2[] = { 1, 2, 3, 5 };
        // Rotate arr1 from 0 to 2(m-n) then swap arr1 and arr2
        RotateArr(arr1,m,m-n);
        // int ar1[] = { 10, 13, 15, 20, 8, 9 };
        for(int i = 0; i < n; i++)
        {
            swap(arr1[i],arr2[i]);
            // int ar1[] = { 1, 2, 3, 5, 8, 9 };
            // int ar2[] = { 10, 13, 15, 20 };
        }
    }
    else
    {
        MergeMoreOpt(arr1,m,arr2,n);
    }
}


int main()
{
    // int m = 3, n = 4;
    // int arr1[m] = {1,4,7};
    // int arr2[n] = {2,3,5,6};

    int arr1[] = { 1, 5, 9, 10, 15, 20 };
    int arr2[] = { 2, 3, 8, 13 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    MergeArrMoreOpt(arr1,m,arr2,n); 
    PrintArr(arr1,m);
    PrintArr(arr2,n);

    return 0;
}