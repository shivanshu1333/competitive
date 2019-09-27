#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
#define s second
vector<int> xr = {-2,-1,-2,-1,1,2,2,1};
vector<int> yc = {1,2,-1,-2,-2,-1,1,2};

int trap(vector<int>& h) {
    stack<int> stk;
    int i = 0;
    int ans=0;
    for(i=0;i<h.size();i++){
        if(stk.empty() || h[i]<=h[stk.top()]){
            stk.push(i);
        }
        else if(h[i]>h[stk.top()]){
            while(!stk.empty() && h[i]>h[stk.top()]){
                int top = stk.top();
                stk.pop();
                if(!stk.empty()){
                    ans+= (min(h[stk.top()], h[i])-h[top])*(i-stk.top()-1);
                }
            }
            stk.push(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<trap(v)<<endl;
}