#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<vector<ll>> vll;
typedef vector<ll> vl;

ll doc_chunk(vll &uc, ll n){
    ll ans=0;
    ll cnt=0;
    sort(uc.begin(), uc.end());
    ll prev=0;
    for(int i=0;i<uc.size();i++){
        cnt = uc[i][0]-1-prev;
        ans += __builtin_popcount(cnt);
        prev = uc[i][1];
    }
    cnt = n-prev;
    ans += __builtin_popcount(cnt);
    return ans;
}

int main(){
    vll uc = {{2,4}, {7,8}, {14,15}};
    ll n = 15; 
    ll ans = doc_chunk(uc, n);
    cout<<ans<<endl;
}