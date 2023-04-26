#include<bits/stdc++.h>

using namespace std;

// first repeating element
/* Given an array of integers, find the first 
 * repeating element in it. We need to find the 
 * element that occurs more than once and whose 
 * index of first occurrence is smallest. 
 */

int firstRepeated(int arr[], int n) {
    unordered_set<int> s;
    int fr = -1;

    for(int i = n-1; i >= 0; i--)
    {
        if(s.find(arr[i]) != s.end())
        {
            fr = arr[i];
        }
        else
        {
            s.insert(arr[i]);
        }
    }
    return fr;
}

int firstRepeatedAlt(int arr[], int n) {
    //code here
    unordered_map<int,int> m;
    m[arr[0]]=0;
    int min=1000000;
    for(int i=1;i<n;i++)
    {
    	//search if that element exists
        if(m.find(arr[i])!=m.end())
        {
            int newmin=m[arr[i]]+1;
            //check if that is small
            if(newmin<min)
                min=newmin;
        }
        else
        {
        //if not exists add in map
            m[arr[i]]=i;
        }
        
    }
    return min==1000000?-1:arr[min-1];
}

int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstRepeated(arr, n);
    return 0;
}