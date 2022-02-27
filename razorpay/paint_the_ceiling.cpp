#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
#define ll long long
ll paint(int n, int k, int b, int m, int s0, ll a){
    vl s(n, 0);
    s[0]=s0;
    ll ans=0;
    for(int i=1;i<n;i++)
        s[i] = (((k*s[i-1] + b)%m) +1 +s[i-1]);
    int l=0, r=n-1;
    while(l<=r){
        if(s[l]*s[r]<=a){
            ans = ans + 2*(r-l+1)-1;
            l++;
        }
        else{
            r--;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int s0;
    cin>>s0;
    int k, b, m;
    ll a;
    cin>>k>>b>>m>>a;
    cout<<paint(n, k, b, m, s0, a)<<endl;
}