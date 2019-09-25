#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
#define s second
vector<int> xr = {-2,-1,-2,-1,1,2,2,1};
vector<int> yc = {1,2,-1,-2,-2,-1,1,2};

int main(){
fast;
// freopen("i.txt", "r", stdin);
// freopen("o.txt", "w", stdout);
    int n,k;
    string s;
    cin>>n>>k>>s;   
    int cnt=0;
    bool fl=0;
    int ind=1;
    if(n==k)
        cout<<0<<endl;
    else if(k==0)
        cout<<s<<endl;
    else{
    if(s[0]!='1'){
        s[0]='1';
        k--;
        fl=1;
    }
    while(cnt<k && ind<s.length()){
        if(s[ind]!='0'){
            cnt++;
            s[ind]='0';
        }
        ind++;
    }
    // cout<<cnt<<" "<<k<<" "<<ind<<endl;
    // if(cnt<k)
    //     cout<<0<<endl;
    // else if(cnt==k && fl==1 && ind==n)
    //     cout<<0<<endl;
    // else
        cout<<s<<endl;
    }
}