#include<bits/stdc++.h>

using namespace std;

// Maximum Cuts
/* Given a rod of length L, the task is to cut the rod 
 * in such a way that the total number of segments of 
 * length p, q and r is maximized. The segments can only 
 * be of length p, q, and r. 
*/

int fun(int t, int a, int b, int c)
{
    if(t < 0)
        return -1;

    if(t == 0)
        return t;

    int x = fun(t-a,a,b,c);
    int y = fun(t-b,a,b,c);
    int z = fun(t-c,a,b,c);;

    if(x != -1) 
        x++;
    if(y != -1)
        y++;
    if(z != -1)
        z++;

    return max(x,max(y,z));
}
int maxNum(int m1, int m2, int m3){
	cout<<m1<<m2<<m3<<endl;
	return max(max(m1,m2),m3);
}

int funrec(int n, int a, int b, int c, vector<int>& dp){
	if(n==0)
		return 0;
	else if(n<0)
		return -1;
		
	if(dp[n] != -1)
	    return dp[n];
	    
	int m1 = funrec(n-a,a,b,c,dp);
	int m2 = funrec(n-b,a,b,c,dp);
	int m3 = funrec(n-c,a,b,c,dp);

	return dp[n]=maxNum(m1>=0?m1+1:-1,
				  m2>=0?m2+1:-1,
				  m3>=0?m3+1:-1);
}

int main()
{
    // 7 2 3 5
    int total,a,b,c;
    cin>>total;
    cin>>a;
    cin>>b;
    cin>>c;

    cout<< fun(total,a,b,c);
    return 0;
}