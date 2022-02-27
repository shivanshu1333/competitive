//preprocessing saves time
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int main() {
    int T;
    cin>>T;
    vector<ll> ans(10002, -1);
    ans[0]=1;
    int p2, p3, p5;
    p2=p3=p5=0;
    int i=1;
    while(i<10001){
        ll mv = min(min(ans[p2]*2, ans[p3]*3), ans[p5]*5);
        ans[i]=mv;
        if(mv==ans[p2]*2) p2++;
        if(mv==ans[p3]*3) p3++;
        if(mv==ans[p5]*5) p5++;
        i++;
    }
    while(T--){
        int n;
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
}