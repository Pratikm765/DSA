#include<bits/stdc++.h>

using namespace std;

/* Given an array of n distinct elements, find 
 * the minimum number of swaps required to sort the array.
 */

int MinSwaps(int arr[], int n)
{
    int minSwaps = 0;
    pair<int,int> pos[n];

    for(int i = 0; i < n; i++)
    {
        pos[i].first = arr[i];
        pos[i].second = i;
    }

    sort(pos,pos+n);

    vector<int> visited(n,false);

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == true)
            continue;
        
        if(i == pos[i].second)
        {
            visited[i] = true;
            continue;
        }
        
        int j = i;
        int cycle = 0;
        while(!visited[j])
        {
            visited[j] = true;
            j = pos[j].second;
            cycle++;
        }

        if(cycle > 0)
            minSwaps += cycle - 1;
    }
    return minSwaps;
}

int main()
{
    int arr[] = {1, 5, 4, 3, 2};
               //0  1  2  3  4  
               //1  2  3  4  5
               //0  4  3  2  1
    int n = (sizeof(arr) / sizeof(int));
    cout << MinSwaps(arr, n);
    return 0;
}