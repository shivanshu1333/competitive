#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bool find(string a, string b){
    if(a.length()!=b.length()) return 0;
    map<int, vector<char>> m1, m2;
    for(int i=0;i<a.length();i++){
        m1[i%2].pb(a[i]);
    }
    for(int i=0;i<b.length();i++){
        m2[i%2].pb(b[i]);
    }
    sort(m1[0].begin(), m1[0].end());
    sort(m1[1].begin(), m1[1].end());
    sort(m2[0].begin(), m2[0].end());
    sort(m2[1].begin(), m2[1].end());
    if(m1[0]==m2[0] && m1[1]==m2[1]) return 1;
    return 0;
}


int main(){
    string a, b;
    cin>>a>>b;
    if(find(a, b)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}