// 5
// 1 1 1 1
// 1 -1 -1 -1 -1
// output 1
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int,int> pii;
    
bool dfs(int c, int p, vector<vector<int>> &g, vector<int> &sv, long long &sum, bool l){
    bool ans=1;
    // cout<<"c "<<c<<" p "<<p<<" sum "<<sum<<endl;
    // cout<<g[c].size()<<endl;
    if(g[c].size()==0){
        if(l==0){
            sum+=0;
        }
        else{
            if(c>1)
                sum+=sv[c]-sv[p];
            else
                sum+=sv[c];
        }
        return ans;
    }
    else{
        for(int i=0;i<g[c].size();i++){
            if(l==0){
                int mv=INT_MAX;
                for(int i=0;i<g[c].size();i++)
                    mv = min(mv, sv[g[c][i]]);
                if(mv<sv[p]){
                    return 0;
                }
                else{
                    sv[c]=mv;
                    ans = ans && dfs(g[c][i], c, g, sv, sum, l^1);
                }                
            }
            else if(l==1){
                if(sv[c]<sv[p]&&c!=1)
                    return 0;
                else{
                    ans = ans && dfs(g[c][i], c, g, sv, sum, l^1);
                }
            }
        }
    
    }
    sum+=sv[c]-sv[p];
    return ans;
}
    
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int v;
    cin>>v;
    vector<vector<int>> g(v+1);
    int tmp;
    for(int i=2;i<=v;i++){
        cin>>tmp;
        g[tmp].push_back(i);
    }
    vector<int> sv(v+1);
    // sv[0]=INT_MAX;
    for(int i=1;i<=v;i++){
        cin>>tmp;
        sv[i]=tmp;
    }
    long long sum=0;
    if(dfs(1, 0, g, sv, sum, 1)){
        cout<<sum<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}