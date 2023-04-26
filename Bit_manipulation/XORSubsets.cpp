#include <bits/stdc++.h>

using namespace std;

int XORofSubsets(int Set[], int n)
{
    // XOR = X
    // X(X(1),X(2),X(3),X(1,2),X(1,3),X(2,3),X(1,2,3))
    // above equals to X(X(1,1,1,1),X(2,2,2,2),X(3,3,3,3))
    if(n == 1)
        return Set[0];
    
    return 0;
}

int main()
{
    int Set[] = { 1, 2, 3 };
    int n = sizeof(Set) / sizeof(Set[0]);
    cout <<  XORofSubsets(Set, n);
    return 0;
}