#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<utility>
// #include<algorithm>
// #include<string>
// #include<stack>
#include<queue>
// #include <fstream>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++)
        cin>>p[i];
    // vector<vector<int>> v(n+1, vector<int> (n+1));
    long long ans = 0;
    // int mv = 0;
    // int mav = 0;
    vector<vector<pair<int,int>>> pa(n+1, vector<pair<int,int>> (n+1));
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(j==i+1){
                // v[i][j] = min(p[i], p[j]);
                pa[i][j].first = min(p[i], p[j]);
                pa[i][j].second = max(p[i], p[j]);
                // mv = pa[i][j].first;
                // mav = pa[i][j].second;
                ans+=pa[i][j].first;
                // continue;
                // cout<<pa[i][j].first<<" fr "<<pa[i][j].second<<endl;
            }
            else if(p[j]>pa[i][j-1].second){
                 pa[i][j].first = pa[i][j-1].second;
                 pa[i][j].second = p[j];
                //  mv = pa[i][j].first;
                //  mav = pa[i][j].second;
                //  cout<<pa[i][j].first<<" fr "<<pa[i][j].second<<endl;
                 ans+=pa[i][j].first; 
            }
            else if(p[j]<pa[i][j-1].second && p[j]>pa[i][j-1].first){
                 pa[i][j].first = p[j];
                 pa[i][j].second = pa[i][j-1].second;
                //  mv = pa[i][j].first;
                //  mav = pa[i][j].second;
                 ans+=pa[i][j].first;
                //  cout<<pa[i][j].first<<" fr "<<pa[i][j].second<<endl;
            }
            else if(p[j]<pa[i][j-1].first){
                 pa[i][j]=pa[i][j-1];
                // cout<<pa[i][j].first<<" fr "<<pa[i][j].second<<endl;
                 ans+=pa[i][j].first;                
            }
            // cout<<"p[j] "<<p[j]<<" ";
            // cout<<"x"<<i<<j<<" ";
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}