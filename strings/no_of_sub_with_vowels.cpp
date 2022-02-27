#include<bits/stdc++.h>
using namespace std;
// abc->3, idea is count all subs contaning ith element
int findVowelsSubstr(string s){
    int n=s.length();
    vector<int> v(n, 0);
    v[0]=n;
    int ans=0;
    for(int i=1;i<n;i++)
        v[i] = v[i-1]+(n-i)-i;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            ans+=v[i];
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<findVowelsSubstr(s)<<endl;
}