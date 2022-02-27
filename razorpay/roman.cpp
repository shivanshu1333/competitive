#include<bits/stdc++.h>
using namespace std;
map<char, int> m = { {'I', 1},
                        {'V', 5},
                        {'X', 10},
                        {'L', 50},
                        {'C', 100},
                        {'D', 500},
                        {'M', 1000}
                    };

vector<string> splitByD(string &s, char D){
    stringstream ss(s);
    string item;
    vector<string> vals;
    while(getline(ss, item, D)){
        vals.push_back(item);
    }
    return vals;
}

int rTi(string s){
    int ans=m[s[s.size()-1]];
    for(int i=s.size()-2;i>=0;i--){
        if(m[s[i]]<m[s[i+1]]) ans-=m[s[i]];
        else ans+=m[s[i]];
    }
    return ans;
}

bool comp(string a, string b) {
    vector<string> s1 = splitByD(a, ' ');
    vector<string> s2 = splitByD(b, ' ');
    if (s1[0] < s2[0]) return true;
    if (s1[0] == s2[0] and rTi(s1[1]) <= rTi(s2[1]))
        return true;
    return false;   
}

int main(){
    vector<string> n = {"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
    sort(n.begin(), n.end(), comp);
    for (int i=0;i<n.size();i++)
        cout<<n[i]<<endl;
return 0;
}