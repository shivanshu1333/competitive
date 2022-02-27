#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pb push_back
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> ans(n);
        stack<ll> stk;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++){
            while(!stk.empty() && v[stk.top()]<=v[i]){
                ans[stk.top()]=v[i];
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()]=-1;
            stk.pop();
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}