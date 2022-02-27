#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
ll v[2000001];
ll dp[1000001];
ll ps[2000001];
ll vm=2000001;
ll dpm=1000001;

ll findsum(ll n){
    ll ev=0;
    ll od=0;
    ll val=0;
    while(n>0){
        val=n%10;
        if(val%2==0)
            ev+=val;
        else
            od+=val;
        n/=10;
    }
    return abs(ev-od);
}

int main(){
    memset(v, 0, sizeof(v));
    memset(ps, 0, sizeof(ps));
    memset(dp, 0, sizeof(dp));
    for(ll i=1;i<vm;i++)
        v[i]=findsum(i);
    dp[1]=2;
    for(ll i=1;i<vm;i++)
        ps[i]=ps[i-1]+v[i];

    for(ll i=2;i<dpm;i++)
        dp[i]=dp[i-1]+v[2*i]+2*(ps[2*i-1]-ps[i]);
    ll T;
    cin>>T;
    while(T--){
        ll nn;
        cin>>nn;
        cout<<dp[nn]<<endl;
    }
}