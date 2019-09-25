#include<iostream>
#include<vector>
#include<climits>
// #include<algorithm>
#include<string>
// #include<stack>
// #include<queue>

// #include <fstream>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
    long long t;
    cin>>t;
    string s;
    string r;
    while(t--){
        cin>>s;
        long long ans=0;
        for(long long i=0;i<s.size();i++){
            for(long long j=i;j<s.size();j++){
                r = s.substr(i,(j-i)+1);
                long long val = stoull(r, 0, 2);
                // cout<<"val "<<val<<endl;
                if(val==(j-i)+1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    
      
}