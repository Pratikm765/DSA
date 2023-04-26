#include<bits/stdc++.h>

using namespace std;

/* Project Euler 50: Which prime, below one-million, 
 * can be written as the sum of the most consecutive 
 * primes?
 */

int ConsecPrime(int n)
{
    int result = 0;
    int max_length = 0;
    vector<bool> primes(n,true);
    for(int i = 2; i*i < n; i++)
    {
        if(primes[i])
        {
            for(int j = i*i; j < n; j+=i)
            {
                primes[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i < n; i++)
    {
        if(primes[i] == true)
            prime.push_back(i);
    }

    for(int i = 0; i < prime.size(); i++)
    {
        int sum = prime[i];;

        for(int j = i+1; j < prime.size(); j++)
        {
            sum += prime[j];

            if(sum > n)
            {
                break;
            }
            if(binary_search(prime.begin(),prime.end(),sum))
            {
                if(max_length<j-i+1)
	            {
	            	max_length=j-i+1;
	            	result = sum;
	            }
                
            }
        }
    }

    return result;
}

int main()
{
    cout << ConsecPrime(1000);
    return 0;
}