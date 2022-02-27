#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int a, b;
    cin>>a>>b;
    int x = a*b;
    vector<int> v;
    int t;
    for(int i=31;i>=0;i--){
        t = x & 1<<i;
        if(t==0)
            v.pb(0);
        else v.pb(1);
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i];
}