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
    // vector<int> v(4);
    // for(int i=0;i<4;i++)
    //     cin>>v[i];
    // sort(v.begin(), v.end());
    // if((v[0]+v[3]==v[1]+v[2])||(v[0]+v[2]==v[1]+v[3])||(v[3]==v[1]+v[2]+v[0]))
    //     cout<<"YES"<<endl;
    // else
    //     cout<<"NO"<<endl;
    set<int> s = {1,2,3,4,5};
    map<int, int> m = {{1,2}, {2,3}};
    cout<<m.rbegin()->f;
}