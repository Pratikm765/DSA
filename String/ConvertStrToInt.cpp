#include <bits/stdc++.h>
using namespace std;

int main() {
   string str = "7";
   int num;

   //num = stoi(str);

   stringstream ss(str);
   ss >> num;

   cout << num;
   return 0;
}