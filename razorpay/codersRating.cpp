#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vl;
typedef pair<int, int> pii;
#define ff first
#define ss second

ll BIT[100001];
void add(int k){
    for(int i=k;i<=100000;){
        BIT[i]++;
        i = i+(i&(-i));
    }
}
ll sum(int k){
    ll ans = 0;
    for(int i=k; i>0; ){
        ans += BIT[i];
        i = i - (i & (-i));
    }
    return ans;
}

int main(){
    int N,A,H;
    cin >> N;
    vl res(N);
    pair<pii, int> coder[N];
    for(int i=0; i <N; i++){
        cin>>A>>H;
        coder[i]={{A, H}, i};
    }
    sort(coder, coder+N);
    add(coder[0].ff.ss);
    res[coder[0].ss] = sum(coder[0].ff.ss);
    for(int i=1;i<N;i++){
        if(coder[i].ff.ff == coder[i-1].ff.ff && coder[i].ff.ss == coder[i-1].ff.ss){
            add(coder[i].ff.ss);
            res[coder[i].ss] = res[coder[i-1].ss];
        }
        else{
            add(coder[i].ff.ss);
            res[coder[i].ss] = sum(coder[i].ff.ss);
        }
    }
    for(int i=0;i<N;i++)
        cout<<res[i]-1<<endl;
    return 0;
}