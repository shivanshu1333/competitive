#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int q(map<int, int> &mp, int ind, int t){
    int an = 0;
    if(ind==mp.size())
        return 0;
    auto it=mp.begin();
    int i=ind;
    for(int i=0;i<ind;i++)
        it++;
    for(;it!=mp.end();it++,i++){
        if(it->first>=t)
            an = max(an, q(mp, i+1, it->ff+it->ss)+1);
    }
    return an;
}

int maxEvents(vector<int> a, vector<int> d){
    int an=0;
    map<int, int> mp;
    for(int i=0;i<a.size();i++){
        if(mp.find(a[i])==mp.end())
            mp[a[i]] = d[i];
        else
            mp[a[i]]==min(mp[a[i]], d[i]);
    }
    return q(mp,0,1);
}
int main(){
    vector<int> a = {1,1};
    vector<int> b = {1,5};
    cout<<maxEvents(a, b);
}