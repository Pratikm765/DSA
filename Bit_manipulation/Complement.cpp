#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 26;
    cout << "Number: " << num << " Size: " << sizeof(num) << endl;

    bitset<32> x(num);
    cout << "Binary Form: " << x << endl;
    
    x = num = ~num;
    cout << "1's Complement: " << x << " << " << num << endl;

    x = num = num + 1;
    cout << "2's Complement: " << x << " << " << num << endl; 
    return 0;
}