#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef double dd;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<double> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<ll> cl(n);
    vector<ll> fl(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cl[i] = ceil(v[i]);
        fl[i]= floor(v[i]);
        sum+=cl[i];
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(cl[i]==fl[i])
            ans[i]=cl[i];
        else if(sum>0){
            ans[i]=fl[i];
            sum--;
        }
        else{
            ans[i]=cl[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}