#include<bits/stdc++.h>

using namespace std;

int knapsackrec(int wt[], int price[],int n,int w){
    if(n==0||w==0)
        return 0;
    
    if(wt[n-1]<=w)
        return max(price[n-1]+knapsackrec(wt,price,n-1,w-wt[n-1]),knapsackrec(wt,price,n-1,w));
    else
        return knapsackrec(wt,price,n-1,w);
}

// weight[] = {1, 1, 1}, W = 2, profit[] = {10, 20, 30}
// K(n,W)

//                             K(3, 2)
// 				         /                  \
// 			  	        /   				 \
//                     / 0                    \ 30
//                    /                        \               
//              K(2, 2)                         K(2, 1)
//             /       \                        /    \ 
//            / 0       \ 20                   /0     \20 
//           /           \                    /        \
//       K(1, 2)         K(1, 1)         K(1, 1)       K(1, 0)
//       /0    \10       /0    \10       /0   \10        
//      /       \       /       \       /      \      
//   K(0, 2)  K(0, 1) K(0, 1) K(0, 0) K(0, 1)  K(0, 0) 

int knapsackrecMemo(int wt[], int price[],int n,int w,vector<vector<int>>& dp){
    if(n==0||w==0)
        return 0;

    if(dp[n][w]!=-1)
        return dp[n][w];
    
    if(wt[n-1]<=w)
        dp[n][w]=max(price[n-1]+knapsackrecMemo(wt,price,n-1,w-wt[n-1],dp),knapsackrecMemo(wt,price,n-1,w,dp));
    else2
        dp[n][w]=knapsackrecMemo(wt,price,n-1,w,dp);

    return dp[n][w];
}

// weight[] = {1, 1, 1}, W = 2, profit[] = {10, 20, 30}
// K(n,W) = K(3,2)

//      0   1   2   
//  0   0   0   0   
//  1   0   10  10 
//  2   0   20  30
//  3   0   30  50

int knapsackTopDown(int wt[], int price[],int n,int w){

    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
                dp[i][j]=max(price[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][w];
}

int main(){
    int price[]={60,100,120};
    int wt[]={10,20,30};
    int w=50;
    int n = sizeof(price) / sizeof(price[0]);

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

    // for(int i=0;i<=n;i++)
    // {
    //     for (int j = 0; j <=n; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     } 
    //     cout<<endl;
    // }

    cout<<knapsackrec(wt,price,n,w)<<endl;
    cout<<knapsackrecMemo(wt,price,n,w,dp)<<endl;
    cout<<knapsackTopDown(wt,price,n,w)<<endl;
    return 0;
}

