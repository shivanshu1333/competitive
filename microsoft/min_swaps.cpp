#include<iostream>
#include<vector>
#include<string>
using namespace std;

int func(char *s){
    int n=0;while(s[n]!='\0') n++;
    vector<int> v(26, 0);
    for(int i=0;i<n;i++) v[s[i]-'a']++;
    int occ=0;
    for(int i=0;i<26;i++) occ+=v[i]&1;
    if(occ>1) return -1;
    int end=n-1, ans=0;
    for(int i=0;i<(n/2);i++){
        if(s[i]==s[end-i]) continue;
        int j, k;
        for(j=i+1;j<=(end-i) && s[j]!=s[end-i]; j++);
        for(k=end-i-1;k>=i && s[k]!=s[i];k--);
        ans += min(j-i, end-i-k);
        if(j<end-k)
            for(int p=j;p>i;p--) swap(s[p], s[p-1]);
        else
            for(int p=k;p<end-i;p++) swap(s[p], s[p+1]);
    }
    return ans;
}

int main(){
    string s;
    while(1){
        cin>>s;
        if(s=="0") break;
        int n=0;
        while(s[n]!='\0') n++;
        char *c = new char[n+1];
        int i=0;
        for(i=0;i<n;i++) c[i]=s[i];
        c[i]='\0';
        int ans = func(c);
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
}