#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef pair<int, int> pii;

int find(vector<vector<string>> &v){
int ans=0;
unordered_map< string,  pair< vector<pii>, vector<pii> > > m;
    for(int i=0;i<v.size();i++){
        string st = v[i][0];
        if(v[i][1]=="BUY")
            m[st].f.pb( {stoi(v[i][3]) , stoi(v[i][2])} );
        else
            m[st].s.pb( {stoi(v[i][3]) , stoi(v[i][2])} );
    }
    for(auto it=m.begin();it!=m.end();it++){
        priority_queue<pii, vector<pii>, greater<pii>> qs;
        priority_queue<pii> qb;
        for(int i=0;i<it->s.f.size();i++)
            qb.push(it->s.f[i]);
        for(int i=0;i<it->s.s.size();i++)
            qs.push(it->s.s[i]);
        while(!qb.empty() && !qs.empty()){
            if(qb.top().f < qs.top().f) break;
            pii bx=qb.top();
            pii sx=qs.top();
            qb.pop();
            qs.pop();
            if(bx.s<sx.s) qs.push({sx.f, sx.s-bx.s});
            else if(bx.s>sx.s) qb.push({bx.f, bx.s-sx.s});
        }
        while(!qb.empty()){
            ans+=qb.top().s;
            qb.pop();
        }
        while(!qs.empty()){
            ans+=qs.top().s;
            qs.pop();
        }
    }
return ans;
}

int main(){
    vector<vector<string>> v = { 
                               {{"GOOGL"},{"BUY"},{"500"},{"784"}},
                               {{"GOOGL"},{"SELL"},{"200"},{"540"}},
                               {{"GOOGL"},{"SELL"},{"200"},{"550"}},
                               {{"AMZN"},{"SELL"},{"200"},{"100"}} ,
                               {{"AMZN"},{"BUY"},{"300"},{"200"}}                               
                            };
    int ans=0;
    cout<<find(v);
}