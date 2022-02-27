#include <bits/stdc++.h>
using namespace std;
int editdis(string src,string dest)
{   
    int m = src.length(),n=dest.length();
    vector <vector <int> > dp(m+1,vector <int>(n+1));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
            else if(src[i-1] == dest[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string src,dst;cin>>src>>dst;
    int dis = INT_MAX;
    for(int i=0;i<26;i++)
    {
        dis = min(dis,editdis(src,dst));
        for(int j=0;j<src.length();j++)
        {
            if(src[j] == 'z') src[j] = 'a';
            else
                src[j] = src[j]+1;
        }
    }
    cout<<dis<<endl;
    return 0;
}