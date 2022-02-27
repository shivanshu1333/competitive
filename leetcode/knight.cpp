#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int r, int c, int i, int j){
        return (i>=0)&&(j>=0)&&(i<r)&&(j<c);
    }
    
    vector<int> ri = {-1, 0, 1, 0};
    vector<int> ci = {0, 1, 0, -1};
    int mod = 1000000007;
    
    int dfs(vector<vector<vector<int>>> &dp, int r, int c, int moves, int i, int j){
        if(moves<=0)
            return 0;
        if(moves == 1){
            int cnt = 0;
            for(int li=0;li<4;li++){
                if(!isSafe(r, c, i+ri[li], j+ci[li]))
                    cnt++;
            }
            return cnt;
        }
        cout<<"i ->"<<i<<" j ->"<<j<<" remaining moves -> "<<moves<<endl;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves]; 
        int ans = 0;
        for(int li=0;li<4;li++){
            if(isSafe(r, c, i+ri[li], j+ci[li])){
                ans = (ans%mod + dfs(dp, r, c, moves-1, i+ri[li], j+ci[li])%mod)%mod;
            }
            else{
                if(moves>1){
                        ans = (ans+1)%mod;
                        // moves = moves-1;
                }                    
            }
        }            
        dp[i][j][moves] = ans;
        return dp[i][j][moves];        
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (N+1, -1)));
        return dfs(dp, m, n, N, i, j);
    }

int main(){
    cout<< findPaths(45, 35, 47, 20, 31);
}