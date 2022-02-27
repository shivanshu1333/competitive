#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int prev=v[0];
    int sum=prev;
    for(int i=1;i<n;i++){
        if(v[i]<=prev){
            prev = prev+1;
            sum+=prev;
        }
        else{
            prev = v[i];
            sum+=prev;
        }
    }
    cout<<sum<<endl;
}