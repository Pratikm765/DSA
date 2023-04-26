#include<bits/stdc++.h>

using namespace std;

/* Find majority votes between two candidates
 */
int majorityWins(int arr[], int n, int x,int y)
{
    int xcount = 0, ycount = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            xcount++;
        if(arr[i] == y)
            ycount++;
    }

    if(xcount == ycount)
        return x>y?x:y;
    else if(xcount > ycount)
        return x;
    else
        return y;
}

// Boyer-Moore Majority Voting Algorithm
/* A majority element in an array A[] of 
 * size n is an element that appears more 
 * than n/2 times.
 */
// Same problem can be solved using hashing 
// unordered_map but it will comprimise n space.
// And also using sorting but then it will
// take nlogn time.
int majorityWins(int arr[], int n)
{
    int cad = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(count == 0)
        {
            cad = arr[i];
            count = 1;
        }
        else
        {
            if(arr[i] != cad)
            {
                count--;
            }
            else
            {
                count++;
            }
        }
    }

    if(count > 0)
    {
        count = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == cad)
                count++;
        }

        if(count > n/2)
            return cad;
    }
    return -1;
}

int main()
{
    int arr[7] = {5,5,5,3,5,4,5};
    cout<<majorityWins(arr,7)<<endl;
    int arr2[10] = {1,0,1,1,1,0,0,1,0,1};
    cout<<majorityWins(arr2,10,0,1);
    return 0;
}