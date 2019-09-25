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
string s="abdef";
string st="23412";
for(int i=0;i<s.length();i++)
    st[i]=s[i];
cout<<st<<endl;
}