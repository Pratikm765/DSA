#include<bits/stdc++.h>

using namespace std;

// Rotated strings
/* Given a string s1 and a string s2, write a function 
 * to check whether s2 is a rotation of s1. 
 */
bool checkStringRotated(string& s1, string& s2)
{
    if(s1.length() != s2.length())
        return false;
        
    string s3 = s1+s1;
    for(int i = 0, j = 0; i < s3.length(); i++)
    {  
        if(s3[i] == s2[j])
        {
            j++;
            if(j == s2.length())
                return true;
        }
        else
        {
            j = 0;
        }
    }
    return false;
}

int main()
{
    string s1 = "abcd";
    string s2 = "cdab";

    if (checkStringRotated(s1, s2))
        cout << "Strings are rotations of each other"
                << endl;
    else
        cout
            << "Strings are not rotations of each other"
            << endl;
    return 0;
}