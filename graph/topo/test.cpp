#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
int inedge[MAX];
vector<int> sandro[MAX];
set<int> nextorder;
vector<int> result;

void topo(){
 int u,v;
 set<int>:: iterator it;
 while(!nextorder.empty()){
  u = *nextorder.begin();
  nextorder.erase(nextorder.begin());
  result.push_back(u);
  for(int i=0;i<sandro[u].size();i++){
   v = sandro[u][i];
   inedge[v]--;
   if(inedge[v]==0)
    nextorder.insert(v);
  }
 }
}
int main(){


 ios_base::sync_with_stdio(false);
 #ifndef ONLINE_JUDGE
 freopen("input.in","r",stdin);
 freopen("output.out","w",stdout);
 #endif

 int n,m,u,v;
 cin>>n>>m;

 for(int i=0;i<m;i++){
  cin>>u>>v;
  inedge[v]++;
  sandro[u].push_back(v);
 }

 for(int i=1;i<=n;i++){
  if(inedge[i] == 0){
   nextorder.insert(i);
  }
 }
 topo();
 if(result.size()!=n){
  cout<<"Sandro fails.\n";
 }else{
  for(int i=0;i<n-1;i++){
   cout<<result[i]<<" ";
  }
  cout<<result[n-1]<<endl;
 }
 return 0;

}