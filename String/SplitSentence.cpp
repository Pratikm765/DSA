#include <bits/stdc++.h>
using namespace std;

/* Give a sentence, print different words present in it. 
 * Words are separated by space. 
 */
void splitSentence(string str, vector<string>& v)
{
    string word = "";
    stringstream ss(str);

    while(getline(ss,word,' ')) //while(ss >> word)
    {
        v.push_back(word);
    }

    // Approach 2:
    // for (auto x : str)
    // {
    //     if (x == ' ')
    //     {
    //         v.push_back(word);
    //         word = "";
    //     }
    //     else {
    //         word = word + x;
    //     }
    // }
    // v.push_back(word);

    // Approach 3
    // char *token = strtok((char*)str.c_str(), " ");
    // while (token != NULL)
    // {
    //     string s(token);
    //     v.push_back(s);
    //     token = strtok(NULL, " ");
    // }
}

int main()
{
    string str = "Geeks for Geeks";
    vector<string> v;
    splitSentence(str,v);
    for(string st : v)
    {
        cout << st <<endl;
    }
    return 0;
}
