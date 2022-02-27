#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        tmp--;
        v[i]=tmp;
    }
    vector<bool> t(n, 0);
    int l=0;
    bool fl=0;
    int ans=0;
    for(int i=0;i<v.size();i++){
        t[v[i]]=1;
        if(t[l]==1){
            while(l<t.size() && t[l]==1){
                l++;
                fl=1;
            }
            if(fl==1) ans++;
            fl=0;
        }
    }
    cout<<ans<<endl;
}