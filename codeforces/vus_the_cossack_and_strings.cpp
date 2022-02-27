#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef double dd;
#define ll long long

int main(){
    string a, b;
    cin>>a>>b;
    vector<int> v(a.length(), 0);
    if(a[0]=='1') v[0]=1;
    for(int i=1;i<v.size();i++){
        if(a[i]=='1') v[i]=v[i-1]+1;
        else v[i]=v[i-1];
    }
    int c=0;
    for(int i=0;i<b.length();i++) if(b[i]=='1') c++;

    int r=b.length()-1;
    int l=0;
    int ans=0;
    if((v[r]-c)%2==0) ans++;
    r++;
    l++;
    while(r<a.length()){
        if((v[r]-v[l-1]-c)%2==0) ans++;
        r++;
        l++;
    }
    cout<<ans<<endl;
}