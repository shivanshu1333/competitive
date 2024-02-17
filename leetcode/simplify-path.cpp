#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

    vector<string> split_with_slash(string s){
        vector<string> v;
        vector<int> ind;
        if(s.length() == 0) return v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='/') ind.push_back(i);
        }
        for(int i=0;i<ind.size()-1;i++){
            v.push_back(s.substr(ind[i]+1, ind[i+1]-ind[i]-1));
        }
        v.push_back(s.substr(ind[ind.size()-1]+1, s.length()-1-ind[ind.size() - 1]));
        return v;
    }

    string simplifyPath(string path) {
        vector<string> v = split_with_slash(path);
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        //     cout<<endl;
        // }
        stack<string> s;
        for(int i=0;i<v.size();i++){
            if(v[i] == ".") continue;
            else if(v[i] == "..") {
                if(!s.empty()) s.pop();
                continue;
            }
            else{
                if(v[i] != "")
                    s.push(v[i]);
            }
        }
        vector<string> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        string xans="";
        for(int i=0;i<ans.size();i++){
            if (ans[i]!="")
                xans = "/" + ans[i] + xans; 
        }
        if (ans.size()==0) return "/";
        return xans;
    }

int main(){
    cout<<simplifyPath("/...")<<endl;
}