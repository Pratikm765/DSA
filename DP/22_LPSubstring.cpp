#include <bits/stdc++.h>

using namespace std;

string LPSubstring(string x,int len)
{
    bool dp[len][len] = {false};
    int maxlen=INT_MIN;
    int start = 0;

    for(int i=len-1;i>=0;i--)
    {
        for(int j=i;j<len;j++)
        {
            if(j-i == 0)
            {
                dp[i][j]=true;
            }
            else if(j-i == 1)
            {
                if(x[i] == x[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if(x[i] == x[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = false;
            }
                

            if(dp[i][j] && maxlen < j-i+1)
            {
                start = i;
                maxlen = j-i+1;
            }
        }
    }
    return x.substr(start, maxlen);;
}  

int main()
{
    cout<<LPSubstring("ababd",5);

    return 0;
}
