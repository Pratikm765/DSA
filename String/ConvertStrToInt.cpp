#include <bits/stdc++.h>
using namespace std;

int my_stoi(const string& s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Handle optional sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    // Convert characters to integer
    while (i < s.length()) {
        if (s[i] < '0' || s[i] > '9') {
            throw invalid_argument("Invalid character in input");
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return sign * result;
}

int main() {
   string str = "7";
   int num;

   //num = stoi(str);

   stringstream ss(str);
   ss >> num;

   cout << num;
   return 0;
}