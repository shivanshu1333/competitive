#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;

bool pre_BST(vi &pre){
    stack<int> stk;
    int root = INT_MIN;
    for(int i=0;i<n;i++){
        if(pre[i]<root) return 0;
        while(!stk.empty() && pre[i]>stk.top()){
            root = stk.top();
            stk.pop();
        }
        stk.push(pre[i]);
    }
    return 1;
}

int main(){
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(pre_BST(v)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}