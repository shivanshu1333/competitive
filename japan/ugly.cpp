#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int soln(int n){
    int tp=0;
    int thp=0;
    vector<int> v(n+1, 1);
    for(int i=1;i<=n;i++){
        v[i] = min(v[tp]*2, v[thp]*3);
        if(v[i] == v[tp]*2) tp++;
        if(v[i] == v[thp]*3) thp++;
    }
    return v[n];
}

int main(){
    int n;
    cin>>n;
    int ans = soln(n);
    cout<<ans;
}