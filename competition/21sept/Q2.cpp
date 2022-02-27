#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    int no;
    for(int i=1;i<=n;i++){
        cin>>no;
        v.push_back({no,i});
    }
    sort(v.begin(), v.end());
    int ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=(v[i].first*(n-1-i)+1);
    }
    cout<<ans<<endl;
    for(int i=n-1;i>=0;i--)
        cout<<v[i].second<<" ";
    cout<<endl;
}