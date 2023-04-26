#include<bits/stdc++.h>

using namespace std;

// Stock buy and sell 
/* The cost of a stock on each day is given in an 
 * array, find the max profit that you can make by
 * buying and selling in those days. 
 */

int maxProfit(int price[], int n)
{
    int profit = 0;
    int buy_price = price[0];

    for(int i = 1; i < n; i++ )
    {
        if(price[i-1] > price[i])
        {
            profit += price[i-1] - buy_price;
            buy_price = price[i];
        }
    }
    profit += price[n-1] - buy_price;
    
    return profit;
}

int main()
{
    int price[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price,n);
    return 0;
}