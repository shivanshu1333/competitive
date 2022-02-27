#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(2049, 0);
        int s;
        for(int i=0;i<n;i++){
            cin>>s;
            if(s<2049)
                v[s]++;
        }
        for(int i=1;i<1025;i++)
            v[2*i]+=v[i]/2;
        if(v[2048]>0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
}