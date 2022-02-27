#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
#include<string>
// #include<stack>
// #include<queue>

using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int cnt = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==t[i])
            cnt++;
    }
    cout<<cnt<<endl;
}