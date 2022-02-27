#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<ll> v(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%3!=0) cout<<0<<endl;
    else if(sum==0){
        ll stn=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            stn+=v[i];
            if(stn==0)
                cnt++;
        }
        if(cnt>0)
            cout<<(ll)(cnt-1)*(ll)(cnt-2)/(ll)2<<endl;
        else
            cout<<0<<endl;
    }
    else{
        vector<ll> cs(n, 0);
        int sbo=0,sbt=0,sbth=0;
        for(int i=0;i<n;i++){
            if(i==0)
                cs[i]=v[i];
            else
                cs[i]=cs[i-1]+v[i];
            if(cs[i]==sum/3)
                sbo++;
            else if(cs[i]==2*sum/3)
                sbt++;
            else if(cs[i]==sum)
                sbth++;
        }
        cout<<(ll)sbo*(ll)sbt*(ll)sbth<<endl;
    }
}