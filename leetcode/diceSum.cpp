#include<iostream>
#include<vector>

using namespace std;

bool dfsUtill(int d, int f, int t){
    if(d==0 && t==0)
        return 1;
    if(d==0 || t<=0)
        return 0;
    bool fl = 0;
    for(int i=1;i<=f;i++){
        fl = fl || dfsUtill(d-1, f, t-i);
    }
    return fl;
}

int dfs(int d, int f, int t){
    int cnt = 0;
    for(int i=1;i<=f;i++){
        if(bool(dfsUtill(d-1, f, t-i)))
            cnt++;
    }
    return cnt;
}

int numRollsToTarget(int d, int f, int t) {
        return dfs(d, f, t);
    }

int main(){
    int d,f,t;
    cin>>d>>f>>t;
    cout<<numRollsToTarget(d, f, t)<<endl;
}