#include<bits/stdc++.h>

using namespace std;

int remove_duplicate(int a[],int n)
{
    sort(a,a+n);
    int i = 0, j = 0;

    while(i < n)
    {
        if((i == 0) || (a[i-1] != a[i]))
        {
            a[j++] = a[i++];
        }
        else
        {
            i++;
        }   
    }
    return j;
}

int main()
{
    int arr[] = {1,2,2,4,5,6,6,6,7,7,8,9,9};
    int len = remove_duplicate(arr,13);

    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}