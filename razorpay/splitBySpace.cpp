#include<bits/stdc++.h>
using namespace std;

vector<string> splitByD(string &s, char D){
    stringstream ss(s);
    string item;
    vector<string> vals;
    while(getline(ss, item, D)){
        vals.push_back(item);
    }
    return vals;
}

int main(){
    string s = "The problemset of Hackerrank repeats a lot";
    vector<string> vs = splitByD(s, ' ');
    int maxl = 0;
    int len;
    for(int i=0;i<vs.size();i++){
        len = vs[i].length();
        if(len%2==0)
            maxl = max(len, maxl);
    }
    bool fl=0;
    for(int i=0;i<vs.size();i++){
        if(vs[i].length()==maxl) {
            cout<<vs[i]<<endl;
            fl=1;
            break;
        }
    }
    if(!fl) cout<<00<<endl;
}