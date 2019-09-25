// #include<algorithm>
#include <iostream>
// #include<vector>
#include<string>
// #include <iomanip>
// #include <queue> 
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s=="10")
    {
        cout<<"1"<<endl;
        return 0;
    }
    else if(s=="11")
     {
        cout<<"1"<<endl;
        return 0;
    }
    else if(s=="100")
     {
        cout<<"1"<<endl;
        return 0;
    }
    int len = s.length();
    int nc = 0;
    for(int i=len-1;i>0;i--){
        if(s[i]=='1')
            nc++;
            // cout<<i<<endl;}
    }
    // cout<<nc<<endl;
    int ans = (len)/2;
    if(nc>0 && (len-1)%2==0)
        ans++;
    cout<<ans<<endl;
}