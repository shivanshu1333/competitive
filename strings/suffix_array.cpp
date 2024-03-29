#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct suffix{
    int in;
    int rnk[2];
};
int comp(struct suffix a, struct suffix b){
    return (a.rnk[0]==b.rnk[0]) ? (a.rnk[1]<b.rnk[1] ? 1:0) : (a.rnk[0]<b.rnk[0] ? 1:0);
}

vector<int> SA(string t, int n){
    struct suffix s[n];
    for(int i=0;i<n;i++){
        s[i].in=i;
        s[i].rnk[0]=t[i]-'a';
        s[i].rnk[1]=((i+1)<n)?(t[i+1]-'a'): -1;
    }
    sort(s, s+n, comp);
    int ind[n];
    for(int k=4;k<2*n;k=k*2){
        int rnk=0;
        int prv_rnk = s[0].rnk[0];
        s[0].rnk[0]=rnk;
        ind[s[0].in]=0;

        for(int i=1;i<n;i++){
            if(s[i].rnk[0]==prv_rnk && s[i].rnk[1]==s[i-1].rnk[1]){
                prv_rnk=s[i].rnk[0];
                s[i].rnk[0]=rnk;
            }
            else{
                prv_rnk=s[i].rnk[0];
                s[i].rnk[0]=++rnk;
            }
            ind[s[i].in]=i;
        }
        for(int i=0;i<n;i++){
            int nin = s[i].in+k/2;
            s[i].rnk[1]=(nin<n)?s[ind[nin]].rnk[0]: -1;
        }
        sort(s, s+n, comp);
    }
    vector<int> suffixA;
    for(int i=0;i<n;i++)
        suffixA.pb(s[i].in);
        return suffixA;
}
vector<int> kasai(string t, vector<int> suffixA){
    int n=suffixA.size();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0);
    for(int i=0;i<n;i++)
        invSuff[suffixA[i]]=i;
    int k=0;
    for(int i=0;i<n;i++){
        if(invSuff[i]==n-1){
            k=0;
            continue;
        }
        int j=suffixA[invSuff[i]+1];
        while(i+k<n && j+k<n && t[i+k]==t[j+k])
            k++;
            lcp[invSuff[i]]=k;
        if(k>0)
            k--;
    }
    return lcp;
}

int count(string s){
    int n=s.length();
    vector<int> suffixA = SA(s, n);
    vector<int> lcp=kasai(s, suffixA);
    int res = n-suffixA[0];
    for(int i=1;i<lcp.size();i++)
        res+=(n-suffixA[i]) - lcp[i-1];
        res++;
        return res;
}
int main(){
    string s="ABCDE";
    // cin>>s;
    int ans = count(s)-1;
    cout<<ans<<endl;
}