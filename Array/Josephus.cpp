#include<bits/stdc++.h>

using namespace std;

/* There are n people standing in a circle waiting 
 * to be executed. The counting out begins at some 
 * point in the circle and proceeds around the circle 
 * in a fixed direction. In each step, a certain number 
 * of people are skipped and the next person is executed. 
 * The elimination proceeds around the circle (which is 
 * becoming smaller and smaller as the executed people 
 * are removed), until only the last person remains, who 
 * is given freedom. Given the total number of person n 
 * and a number k which indicates that k-1 persons are 
 * skipped and the kth person is killed in a circle. The 
 * task is to choose the place in the initial circle so 
 * that you are the last one remaining and so survive.
 */

int Josephus(int n, int k)
{
    int result = 0;
    for(int i = 2; i <= n; i++)
    {
        result = (result+k)%i;//0 2 0 2 
    }
    return result+1;
}

// 1 2 3 4 5
// 1 3 4 5
// 1 3 5
// 3 5
// 3

int main()
{
    cout << Josephus(5,2);
    return 0;
}