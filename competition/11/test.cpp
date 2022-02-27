#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;

void findr(vector<char> &v){
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]=='0'){
            v[i]='1';
            return;
        }
    }
}

void findl(vector<char> &v){
    for(int i=0;i<v.size();i++){
        if(v[i]=='0'){
            v[i]='1';
            return;
        }
    }
}

void func(vector<char> &v,vector<char> &ans){

for(int i=0;i<v.size();i++){
    if(v[i]=='R'){
        findr(ans);
    }

    else if(v[i]=='L'){
        findl(ans);
    }
    else
    {
        ans[(v[i]-'0')]='0';
    }   
}
}

int main(){
    int N;
    cin>>N;
    vector<char> v(N);
    vector<char> ans(10,'0');
    for(int i=0;i<N;i++)
        cin>>v[i];
    func(v,ans);
    for(int i=0;i<10;i++)
        cout<<ans[i];
}