#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    int ma = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ma = max(ma, v[i]);
    }
    if(ma==0){
        cout<<0<<" "<<0<<endl;
    }
    else{
        int mn=0;
        for(int i=0;i<n;i++){
                v[i]=ma-v[i];
                mn = max(mn, v[i]);
        }
        int aa=mn;
        for(int i=0;i<n;i++){
            if(v[i]>0)
                aa = __gcd(aa, v[i]);
        }
        // for(int i=0;i<n;i++) cout<<v[i]<<" ";
        // cout<<endl;
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+= v[i]/aa;
        }
        cout<<ans<<" "<<aa<<endl;
    }
}