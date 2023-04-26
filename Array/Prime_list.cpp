#include<bits/stdc++.h>

using namespace std;

void primeList(int n)
{
    vector<bool> prime(n,true);
    for(int i = 2; i*i < n; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j < n; j+=i)
            {
                prime[j] = false;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(prime[i] == true)
            cout << i << " ";
    }
}

int main()
{
    primeList(100);
    return 0;
}