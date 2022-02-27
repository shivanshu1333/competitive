#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<queue>

using namespace std;

void bfs(vector<vector<int>> &v, int i, int j, int &ma, vector<vector<bool>> &vis,vector<int> &ans){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    vis[i][j]==1;
    int l=0;
    vector<int> pa;
    while(!q.empty()){
        int nc = q.size();
        pa.push_back(v[q.front().first][q.front().second]);
        l++;
        while(nc>0){
            pair<int,int> p = q.front();
            q.pop();
            int ii = p.first;
            int jj = p.second;
            if(ii<v.size() && (jj+1)<v[0].size() && !vis[ii][jj+1] && (abs(v[ii][jj]-v[ii][jj+1])==1))
            q.push(make_pair(ii,jj+1));
            if((ii+1)<v.size() && (jj)<v[0].size() && !vis[ii+1][jj] && (abs(v[ii][jj]-v[ii+1][jj])==1))
                q.push(make_pair(ii+1,jj)); 
            nc--;           
        }
    }
    int ss = pa.size();
    
    if(ss>ma){
        ma = ss;
        ans = pa;
    }
    return;
}

void fss(vector<vector<int>> &v){
    vector<vector<bool>> vis(v.size(),vector<bool> (v.size(),0));
    int ma = INT_MIN;
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(!vis[i][j])
                bfs(v,i,j,ma,vis,ans);
        }
    }
    cout<<ma<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return;    
}

// int main() 
// { 
//     vector<vector<int>> v = 
//     { 
//         {9, 6, 5, 2}, 
//         {8, 7, 6, 5}, 
//         {7, 3, 1, 6}, 
//         {1, 1, 1, 7}, 
//     }; 
  
//     fss(v); 
  
//     return 0; 
// } 

int main() 
{ int T;
cin>>T;
while(T--){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> v(r,vector<int> (c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>v[i][j];
    fss(v); 
}
  
    return 0;
}