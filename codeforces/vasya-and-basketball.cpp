#include<bits/stdc++.h>
using namespace std;
// long long a[200002];
// long long b[200002];
#define ll long long
unordered_map<ll, ll> a,b;

int main(){
    long long an,bn;
    cin>>an;
    long long x;
    long long mx=0;
    for(long long i=0;i<an;i++){
        cin>>x;
        a[x]++;
        mx=max(x, mx);
    }
    cin>>bn;
    for(long long i=0;i<bn;i++){
        cin>>x;
        b[x]++;
        mx=max(x, mx);
    }
    mx++;
    for(long long i=1;i<mx;i++)
        a[i]+=a[i-1];
    for(long long i=1;i<mx;i++)
        b[i]+=b[i-1];
    long long av, bv;
    vector<pair<long long, long long>> p;
    long long diff=LLONG_MIN;
    long long ansa=LLONG_MIN;
    long long ansb=0;
    for(long long d=0;d<mx;d++){
        av=2*(a[d]);
        av+=3*(an-a[d]);
        bv=2*(b[d]);
        bv+=3*(bn-b[d]);
        if(diff<(av-bv)){
            ansa=av;
            ansb=bv;
            diff=av-bv;
        }
    }
    cout<<ansa<<":"<<ansb<<endl;
}