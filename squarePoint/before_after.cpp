#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi getBack(vvi m){
    vvi aux(m.size(), vi (m[0].size(), 0));
    for(int i=0;i<m[0].size();i++)
        aux[0][i] = m[0][i];
    for(int i=1;i<m.size();i++)
        for(int j=0;j<m[0].size();j++)
            aux[i][j]= m[i][j]-aux[i-1][j];
    for(int i=0;i<m.size();i++)
        for(int j=1;j<m[0].size();j++)
            aux[i][j]-=aux[i][j-1];
    return aux;
}

vvi pre(vvi m){
    vvi aux(m.size(), vi (m[0].size(), 0));
    for(int i=0;i<m[0].size();i++)
        aux[0][i] = m[0][i];
    for(int i=1;i<m.size();i++)
        for(int j=0;j<m[0].size();j++)
            aux[i][j]= m[i][j]+aux[i-1][j];
    for(int i=0;i<m.size();i++)
        for(int j=1;j<m[0].size();j++)
            aux[i][j]+=aux[i][j-1];
    return aux;
}

int sumQ(vvi aft, int tli, int tlj, int rbi, int rbj){
    int res = aft[rbi][rbj];
    if(tli>0)
        res -= aft[tli-1][rbj];
    if(tlj>0)
        res -= aft[rbi][tlj-1];
    if(tli>0 && tlj>0)
        res+=aft[tli-1][tlj-1];
    return res;
}

int main(){
    vvi bef = {{2,3},{5,7}};
    vvi aft = pre(bef);
    vvi bef1 = getBack(aft);
    cout<<sumQ(aft, 1, 0, 1, 1)<<endl;
}