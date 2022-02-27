#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//aeioaexaaeuiou - 4
bool vowel(char c){
    return ((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u'));
}

vector<string> find_Vowel_Strings(string &s){
    vector<string> v;
    int i=0, j=0;
    unordered_map<char, bool> m;
    string st="";
    while(j<s.length()){
        if(!vowel(s[j])){
            if(st.length()>=5 && m.size()==5){
                v.pb(st);
                st="";
                i=j;
                m.clear();
            }
            else{
                st="";
                i=j;
            }
        }
        else{
            m[s[j]]=1;
            st+=s[j];
        }
        j++;
    }
    if(st.length()>=5 && m.size()==5){
        v.pb(st);
        st="";
        i=j;
        m.clear();
    }
    return v;
}

int subs(string s){
    int i=0,j=0;
    int ans=0;
    unordered_map<char, int> m;
    while(j<s.size()){
        while(m.size()==5){
            ans += s.length()-j+1;
            m[s[i]]--;
            if(m[s[i]]==0) m.erase(s[i]);
            i++;
        }
        m[s[j]]++;
        j++;
    }
    while(m.size()==5){
        ans += s.length()-j+1;
        m[s[i]]--;
        if(m[s[i]]==0) m.erase(s[i]);
        i++;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> v = find_Vowel_Strings(s);
    int ans=0;
    for(int k=0;k<v.size();k++){
        ans+=subs(v[k]);
    }
    cout<<ans<<endl;
}