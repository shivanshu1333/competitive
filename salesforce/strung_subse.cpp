#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s, t;
        cin>>s>>t;
        int a=0, b=0;
        while(b<t.length()){
            if(s[a]==t[b]){
                a++;
                b++;
            }
            else b++;
        }
        if(a==s.length()) cout<<1<<endl;
        else cout<<0<<endl;
    }
}