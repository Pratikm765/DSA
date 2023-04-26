#include<bits/stdc++.h>
using namespace std;


// Basic Euclidean Algorithm for HCF
// The Euclidean algorithm is based on the below facts:
// If we subtract the smaller number from larger 
// (we reduce larger number), GCD doesn't change. So if we 
// keep subtracting repeatedly the larger of two, we end up with GCD.
// Now instead of subtraction, if we divide the smaller number, 
// the algorithm stops when the remainder is found to be 0.

int findGCD(int a, int b){
    if(a == 0)
        return b;
    
    return findGCD(b%a,a);
}

// a*b = LCM * GCD
int findLCM(int a, int b){
    return (a*b)/findGCD(a,b);
}

int getSmallestDivNum(int n){
    int result = 1;
    for(int i = 2; i <= n; i++){
        result = (result*i)/findGCD(result,i);
    }
    return result;
}

// Using Sieve of Eratosthenes is the most efficient way of 
// generating prime numbers up to a given number N.

// Following is the algorithm to find all the prime numbers 
// less than or equal to a given integer n by Eratosthenes' method:
// 1. Create a list of consecutive integers from 2 to n: (2, 3, 4, ..., n).
// 2. Initially, let p equal 2, the first prime number.
// 3. Starting from p2, count up in increments of p and mark each of these 
// numbers greater than or equal to p2 itself in the list. These numbers 
// will be p(p+1), p(p+2), p(p+3), etc..
// 4. Find the first number greater than p in the list that is not marked. 
// If there was no such number, stop. Otherwise, let p now equal this 
// number (which is the next prime), and repeat from step 3.
void primeList(int n){
    vector<bool> v(n+1,false);

    for(int i = 2; i*i <= n; i++){
        if(v[i] == false)
        {
            for(int j = i*i; j <= n; j+=i)
            {
                v[j] = true;
            }
        }
    }

    for(int i=2; i <= n; i++)
    {
        if(v[i] == false)
            cout << i <<" ";
    }
    cout<<endl;
}


bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more then
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

int exactly3Divisors(int N)
{
    //Your code here
    int cnt=0;
    for(int i=2;i*i<=N;i++){
        if(isPrime(i)) 
            cnt++;
    }
    return cnt;
} 

// Suppose the number of digits in the number N is K.
// 10^(K-1) <= N < 10^K
// K-1 <= log10(N) < K.
// K - 1 + 1 <= log10(N) + 1 < K + 1
// K <= log10(N) + 1 < K + 1 
int totalDigits(int n){
    return floor(log10(n)+1);
}

// A trailing zero is always produced by the 
// prime factors 2 and 5. If we can count the number 
// of 5s and 2s in prime factorization of N!, our task is done.
int trailingZeros(int n){
    int count = 0;
    for(int i = 5; i <= n; i*=5)
    {
        count += floor(n/i);
    }
    return count;
}

int totalDigitsFactorial(int n){
    if(n<=0)
        return 0;
    
    if(n == 1)
        return 1;

    double digits = 0;

    for(int i=2; i<=n; i++){
        digits += log10(i);
    }

    return floor(digits)+1;
}

// A.P
// a(n) = a(1) + (n-1)d
// s(n) = 0.5*n (2*a(1)+ (n-1)*d)
// G.P
// a(n) = a(1) + r^(n-1)
// s(n) = a(r^n - 1)/(r-1)

// quadratic equations
// roots = (-b ± √(b2 - 4ac))/2a

// Permutation nPr = n! / (n - r)! No of arrangements
// Combinations nCr = n! / [ (r !) * (n - r)! ] No of combinations

int main(){

    while(true){
        cout << " Enter Function:\n ";
        cout << " 0. Exit\n";
        cout << " 1. GCD/HCF\n";
        cout << " 2. LCM\n";
        cout << " 3. Prime Number list\n";
        cout << " 4. Total digits in Number\n";
        cout << " 5. Trailing zeros in factorial\n";
        cout << " 6. Smallest Divisible number for range\n";
        cout << " 7. Total Digits in factorial\n";
        cout << " 8. Exactly 3 divisors\n";

        int fn;
        cin >> fn;
        switch(fn){
            case 1:
            {
                int t1, t2;
                cout << "Enter numbers: \n";
                cin >> t1 >> t2;
                cout << "HCF/GCD of " << t1 << " and " << t2 <<
                    " : " << findGCD(t1,t2) << endl;
                break;
            }
            case 2:
            {
                int t1, t2;
                cout << "Enter numbers: \n";
                cin >> t1 >> t2;
                cout << "LCM of " << t1 << " and " << t2 <<
                    " : " << findLCM(t1,t2) << endl;
                break;                
            }
            case 3:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " till " << t1 << ": ";
                primeList(t1);
                break;
            }
            case 4:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " Digits: " << totalDigits(t1) << endl;
                break;
            }
            case 5:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " trailing zeros: " << trailingZeros(t1) << endl;
                break;
            }
            case 6:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " Smallest Divisble number for 0 to "<< t1 <<": "
                 << getSmallestDivNum(t1) << endl;
                break;               
            }
            case 7:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " total Digits in factorial of "<< t1 <<": "
                 << totalDigitsFactorial(t1) << endl;
                break;                   
            }
            case 8:
            {
                int t1;
                cout << "Enter number: \n";
                cin >> t1;
                cout << " Exactly 3 divisors Number between 0 to "<< t1 <<": "
                 << exactly3Divisors(t1) << endl;
                break;                   
            }

        }
        if(fn == 0)
            break;
    }
    return 0;
}