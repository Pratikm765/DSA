#include <bits/stdc++.h>
#define N 4
using namespace std;

int dp[N][N]={0};

//Longest Increasing sequence
//1,10,2,5 => 1,2,5
int LIS(int arr[],int n,int prev,int curr)
{
    //base case if curr reached end of arr
    if(curr==n)
        return 0;
    
    //if we have calculated dp for this path before
    //then jus return that
    //prev!=-1 check is lower bound and arr index cant be -1
    if(prev!=-1 && dp[prev][curr]!=0)
        return dp[prev][curr];

    int incl=0;

    //check if curr element greater than prev
    //if it is then include it
    if(prev==-1 || arr[curr]>arr[prev])
    {
        incl=1+LIS(arr,n,curr,curr+1);
    }

    //exclude curr element 
    int excl=LIS(arr,n,prev,curr+1);

    //assign dp value for the path prev to curr
    if(prev!=-1)
         dp[prev][curr]=max(incl,excl);

    return max(incl,excl);
}

// 1, 10, 2, 5
// 0           1   0   0   0
// 10          1   2   0   0
// 20 21       1   2   2   0 
//             1   2   2   0
// 30 31 32    1   2   2   2
//             1   2   2   2
//             1   2   2   3

int LISTab(int arr[],int n)
{
    int dp[n];
    dp[0]=1;

    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }

    return *max_element(dp,dp+n);
}


int LCSTab(int arr[],int n){
    vector<int> b;
    set<int> s;
 
    // Setting iterator for set
    set<int>::iterator it;
 
    // Storing unique elements
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
 
    // Creating sorted vector
    for (it = s.begin(); it != s.end(); it++) {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];
    for (i = 0; i < m + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}



int main()
{
    int arr[]={1,10,2,5};
    cout<<LIS(arr,4,-1,0);
    return 0;
}