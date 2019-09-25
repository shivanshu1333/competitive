#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;

int main(){
    int N;
    cin>>N;
    int n=N;
    map<string,int> m;
    while(n--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        m[s]++;
    }
    map<string,int> :: iterator it;
    long long ans=0;
    for(it=m.begin();it!=m.end();it++){
        ans+=(long long)(it->second)*(long long)(it->second-1)/2;//////////////////////////////
    }
    cout<<ans;    
}