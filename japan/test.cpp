#include<bits/stdc++.h>
using namespace std;

bool valid(char c){
    int n= c-'a';
    if(n>=0 && n<26) return 1;
    return 0;
}

int func(vector<string> T, vector<string> R){
    int n=T.size();
    unordered_map<int, vector<int>> m;
    for(int i=0;i<n;i++){
        string s = T[i];
        int l=0, r=0;
        int len=s.length();
        while(r<len && valid(s[r])){
            r++;
        }
        l=r;
        while(l<len && !valid(s[l])){
            l++;
        }
        string an=s.substr(r, l-r);
        int num = stoi(an);
        m[num].push_back(i);
    }
    int cnt=0;
    for(auto it=m.begin();it!=m.end();it++){
        vector<int> v=it->second;
        int n=v.size();
        bool ch=0;
        for(int i=0;i<n;i++){
            if(R[v[i]]!="OK"){
                ch=1;
                break;
            }
        }
        if(!ch) cnt++;
    }
    int ms = m.size();
    double ans = ((double)cnt/(double)ms)*100;
    return ans;
}

int main(){
    vector<string> T = {"test1", "test2", "test3a", "test3b"};
    vector<string> R = {"OK", "fgchgb", "gfcghb", "gvgbh"};
    cout<<func(T, R);

}