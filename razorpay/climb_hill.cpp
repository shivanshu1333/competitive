#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//Minimum increment/decrement to make array non-Increasing
int find(vi &v){
    priority_queue<int, vector<int>, greater<int>> q;
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(!q.empty() && q.top()<v[i]){
            sum+=v[i]-q.top();
            q.pop();
            q.push(v[i]);
        }
        q.push(v[i]);
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vi rv=v;
    reverse(rv.begin(), rv.end());
    cout<<min(find(v), find(rv));
}