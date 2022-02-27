#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define f(i,s,e) for(int i=s;i<e;i++)
#define pb push_back

int ans=0;
vi ga;

void ways(vi &v, int l, int r, int x, int i, int s, int mn, int mx, int cnt){
    if(i==v.size()){
       if(cnt>=2 && (mx-mn)<x && s>=l && s<=r){
           ans++;
       }
       return;
    }
    if(s>r) return;
    ways(v, l, r, x, i+1, s, mn, mx, cnt);
    ways(v, l, r, x, i+1, s+v[i], min(mn, v[i]), max(mx, v[i]), cnt+1);
}

int main(){
    int n;
    ga.clear();
    cin>>n;
    vi v(n);
    f(i,0,n) cin>>v[i];
    int l,r,x;
    cin>>l>>r>>x;
    vi an;
    f(i,0,n) if(v[i]<=r) an.pb(v[i]);
    ways(an, l ,r, x, 0, 0, INT_MAX, INT_MIN, 0);
    cout<<ans;
}