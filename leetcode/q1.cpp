#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m;
        int ans=0;
        
        for(int i=0;i<chars.length();i++)
            m[chars[i]]++;
        
        for(int i=0;i<words.size();i++){
            map<char,int> x;
            for(int j=0;j<words[i].length();j++){
                x[words[i][j]]++;
            }
            map<char,int> :: iterator it;
            bool flag = 0;
            for(it=x.begin();it!=x.end();it++){
                if(m.find(it->first)==m.end())
                    flag =1;
                else{
                    if(it->second > m[it->first])
                        flag=1;
                }   
            }
            if(!flag)
                ans += words[i].length();
        }
        return ans;
    }

int main(){
    vector<string> a = {"cat","bt","hat","tree"};
    string b = "atach";
    int ans = countCharacters(a,b);
    cout<<ans;
}