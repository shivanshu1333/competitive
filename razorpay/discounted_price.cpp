#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//2,3,1,2,4,2 - 1,2,1,0,2,2
vi disc(vi &v){
    stack<int> stk;
    int n=v.size();
    vi an(n, 0);
    for(int i=0;i<n;i++){
        while(!stk.empty() && v[i]<=v[stk.top()]){
            an[stk.top()]=v[stk.top()]-v[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        an[stk.top()]=v[stk.top()];
        stk.pop();
    }
    return an;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vi an=disc(v);
    for(int i=0;i<n;i++) cout<<an[i]<<" ";
}