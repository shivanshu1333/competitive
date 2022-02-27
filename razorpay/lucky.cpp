#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        // char a[100000]={0};
        string a;
        int cnt=0;
        cin>>a;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='4'|| a[i]=='7') continue;
            else cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}