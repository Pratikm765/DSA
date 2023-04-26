#include<bits/stdc++.h>

using namespace std;

// Pattern search
/* Given a text txt[0..N-1] and a pattern pat[0..M-1], 
 * write a function search(char pat[], char txt[]) that 
 * prints all occurrences of pat[] in txt[].
 */

// Naieve solution
void search(string pat, string txt)
{
    int m = pat.length();
    int n = txt.length();

    for(int i = 0; i <= n-m; i++)
    {
        int j;
        for(j = 0; j < m; j++)
        {
            if(pat[j] != txt[i+j])
                break;
        }
        if(j == m)
            cout << "Pattern exist from  " << i << " to " << i+j-1 << endl;
    }

}

// Rabin karp
// Uses sliding window technique to match pat
// calculate hash of ti-p.len() using a prime number.
// calculate  hash for initial pat and txt window
// if hash values match then only compare strings
// else decrease ti-p.len() hash from text hash and 
// add next element to calculate next txt window hash.
void search(string pat, string txt, int q)
{
    int m = pat.length();
    int n = txt.length();
    int t = 0;
    int p = 0;
    int d = 256;
    int h = 1;

    for(int i = 0; i < m-1; i++)
    {
        h = (h * d) % q;
    }

    for(int i = 0; i < m; i++)
    {
        t = (t*d + txt[i]) % q;
        p = (p*d + pat[i]) % q;
    }

    for(int i = 0; i <= n-m; i++)
    {
        if(t == p)
        {
            int j;
            for(j = 0; j < m; j++)
            {
                if(pat[j] != txt[i+j])
                    break;
            }
            if(j == m)
                cout << "Pattern exist from  " << i << " to " << i+j-1 << endl;
        }

        if(i < n-m)
        {
            t = (d*(t-h*txt[i])+txt[i+m])%q;
            if(t<0)
                t = t+q;
        }
    }
}

// aaabaacaaab
// 01201201234
// ababcababab
// 00120123434
// LPS identifies repeatating patterns in string
// i. Start with index = 1 as first index will not have any repeating char.
// ii. start comparing the i = 1 with j = 0
//      a. If matched then increase len and add into LPS array
//      b. If dont match 
//          I. if len > 0 then len = lps[len-1]
//          II. else add 0 into LPS array
void calculateLPS(string pat, vector<int>& v)
{
    int i = 1;
    v.push_back(0);
    int len = 0;

    while(i < pat.length())
    {
        if(pat[i] == pat[len])
        {
            len++;
            v.push_back(len);
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = v[len-1];
            }
            else
            {
                v.push_back(0);
                i++;
            }
        }
    }
}

// KMP Algorithm
// 1. Calculate LPS array
// 2. Start matching txt and pat from index = 0
// 3. If matched increase indexes for both
// 4. If pat index reach pat length then we found pat
//    Assign pat index with lps[pat index - 1]
// 5. If not matched and txt index < txt length
//    i. if pat index is not 0 then start pat index from 
//          lps[pat index -1] 
//    ii. else increment txt index
void searchKMP(string txt, string pat)
{
    vector<int> lps;
    calculateLPS(pat,lps);

    int t = txt.length();
    int p = pat.length();

    int i = 0;
    int j = 0;
    while(i < t)
    {
        if(pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if(j == p)
        {
            cout << "pattern found from " << i-j << " to " << i-1 << endl;
            j = lps[j-1];
        }
        else if(i < t && pat[j] != txt[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
}


int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
 
    // A prime number
    int q = 101;
 
    // function call
    search(pat,txt);
    search(pat, txt, q);
    searchKMP(txt,pat);
    return 0;
}