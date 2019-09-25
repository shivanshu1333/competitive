#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int noa=0;
    int nob=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a')
            noa++;
        if(s[i]=='b')
            nob++;
        if(i%2==1){
            if((noa-nob)!=0){
                ans++;
            }
            if(noa>nob)
                s[i]='b';
            else if(nob>noa)
                s[i]='a';
            noa=0;
            nob=0;
        }
    }
    cout<<ans<<endl<<s<<endl;
}