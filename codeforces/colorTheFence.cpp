#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(9, 0);
    int u;
    int ma=0;
    char c;
    for(int i=0;i<9;i++){
        cin>>u;
        v[i]=(int)n/u;
        ma = max(v[i], ma);
    }
    if(ma==0)
        cout<<-1<<endl;
    else{
        for(int i=0;i<9;i++)
            if(ma==v[i])
                c=(i+1)+'0';
        string s;
        for(int i=0;i<ma;i++)
            s+=c;
        cout<<s<<endl;
    }
}