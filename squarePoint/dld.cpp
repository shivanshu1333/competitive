#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool sol(string s){
    stack<char> stk;

    for(inti=0;i<s.length();i++){
        if(s[i]=='[' || s[i]=='|' || s[i]=='!' || s[i]=='&' || s[i]=='0' || s[i]=='1'||)
            st.push(s[i]);
        else if(s[i]==']'){
            string tmp="";
            while(stk.top()!='['){
                tmp+=stk.top();
                stk.pop();
            }
            stk.pop();
            reverse(tmp.begin(), tmp.end());
            if(tmp.length()==2){

            }
            else if(tmp.length()==3){
                
            }
        }
    }
}

int main(){
    string s = "[|, [&, 1, [!, 1]], [!, [&, [|, 0, 0], [!, 0]]]]";

    bool ans = sol(s);
}