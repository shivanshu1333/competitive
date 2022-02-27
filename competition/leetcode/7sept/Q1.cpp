#include<iostream>
#include<vector>
#include<map>
// #include<climits>
// #include<map>
#include<algorithm>
#include<string>
// #include<stack>
// #include<queue>
#include <fstream>
using namespace std;

    int countLetters(string s) {
        int l = s.length();
        map<char, vector<int>> m;
        vector<int> v(l, 1);
        for(int i=1;i<l;i++){
            if(s[i]==s[i-1])
                v[i]+=v[i-1];
            else{
                m[s[i-1]].push_back(v[i-1]);
            }
        }
        m[s[l-1]].push_back(v[l-1]);
        long long ans = 0;
        map<char, vector<int>> :: iterator it;
        for(it=m.begin();it!=m.end();it++){
            int maxn = *max_element(it->second.begin(),it->second.end());
            // cout<<it->first<<" "<<maxn<<endl;
            for(int i=0;i<it->second.size();i++){
                // cout<<it->first<<" "<<it->second[i]<<" ";
                for(int k=0;k<maxn;k++){
                    // cout<<k<<endl;
                    if((it->second[i]-k)>0){
                        ans+=it->second[i]-k;
                    }
                }

            }
        }
        cout<<ans;
        return 0;
    }

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    countLetters(s);
}