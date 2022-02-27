#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

ll f(ll input1, ll input2){
    ll L=input1;
    ll M=input2;
    if(L<1) return 0;
    queue<ll> q;
    q.push(2);
    ll nc=0;
    ll l=1;
    ll ans = 0;
    while(!q.empty()){
        nc = q.size();
        ans = ((ans%M + nc%M)%M + M)%M;
        if(l==L) return ans;
        while(nc>0){
            ll pa = q.front();
            q.pop();
            nc--;
            ll lim = (pa*pa+1)%M;
            for(auto i=0;i<lim;i++)
                q.push(i);
        }
        l++;
    }
    return ans;
}


int main(){
    int input1;
    int input2;
    cin>>input1>>input2;
    cout<<f(input1, input2)<<endl;
}