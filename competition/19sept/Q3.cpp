#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int c,m,x;
        cin>>c>>m>>x;
        if(x<c && x<m){
            cout<<x+min(min((c-x),(m-x)), (c-x+m-x)/3)<<endl;
        }
        else
            cout<<min(min(c, m), x)<<endl;
    }
}