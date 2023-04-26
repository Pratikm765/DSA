#include<bits/stdc++.h>

using namespace std;

// Minimum cost for acquiring all coins with k extra 
// coins allowed with every coin
/* You are given a list of N coins of different 
 * denominations. You can pay an amount equivalent 
 * to any 1 coin and can acquire that coin. In 
 * addition, once you have paid for a coin, we can 
 * choose at most K more coins and can acquire those 
 * for free. The task is to find the minimum amount 
 * required to acquire all the N coins for a given 
 * value of K.
 */

int minCost(int coins[], int n, int k)
{
    sort(coins,coins+n);

    // multiply result with 1.0 as we need
    // to find ceil of float result.
    int min_coins = ceil(1.0*n/(k+1));

    int result = 0;
    for(int i = 0; i < min_coins; i++)
    {
        result += coins[i];
    }
    return result;
}

int main()
{
    int coin[] = {100, 20, 50, 10, 2, 5};
    int n = sizeof(coin) / sizeof(coin[0]);
    int k = 3;
    cout << minCost(coin, n, k)<<endl;
    return 0;
}