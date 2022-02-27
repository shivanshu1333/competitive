#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void bin(int a, vector<int> &ans){
    string s="";
    for(int i=7;i>=0;i--){
        int val = a & 1<<i;
        if(val==0) s+='0';
        else s+='1';
    }
    for(int i=0;i<s.length();i++) ans.pb(s[i]-'0');
}

int main(){
    vector<vector<int>> px = {
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9},
                                {10,11,12},
                                {13,14,15},
                                {16,17,18}
                            };
    int n = px.size();
    int gt = n/3, bt = 2*n/3;
    vector<int> ans;
    for(int i=0;i<(n/3);i++){
        for(int j=0;j<px[0].size();j++){
            bin( px[i][j], ans );
            bin( px[i+gt][j], ans );
            bin( px[i+bt][j], ans );
        }
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
}