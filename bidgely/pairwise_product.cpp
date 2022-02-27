#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef long long ll;
int m = 1000000007;

ll findSum(int arr[], int n){
    ll sum = 0;
    sort(arr, arr + n);
    int i = 0; 
    while (i < n && arr[i] < 0) {
        if (i != n - 1 && arr[i + 1] <= 0) {
            sum = (sum + (arr[i] * arr[i + 1]) % Mod) % Mod;
            i += 2;
        }
        else
            break;
    }
    int j = n - 1;
    while (j >= 0 && arr[j] > 0) {
        if (j != 0 && arr[j - 1] > 0) {
            sum = (sum + (arr[j] * arr[j - 1]) % Mod) % Mod;
            j -= 2;
        }
        else
            break;
    }
    if (j > i)
        sum = (sum + (arr[i] * arr[j]) % Mod) % Mod;
    else if (i == j)
        sum = (sum + arr[i]) % Mod;
    return sum;
}

int findp(vi &v){
    vi pos, neg;
    for(int i=0;i<v.size();i++){
        if(v[i]>0) pos.pb(v[i]);
        if(v[i]<=0) neg.pb(v[i]);
    }
    ll ans=0;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll np=0, pp=0;
    int pl = pos.size(), nl=neg.size();
    if(pl%2==1 && nl%2==1){
        ans = neg[nl-1]*pos[0];
        for(int i=1;i<nl-1;i=i+2){
            np = ((np + neg[i]*neg[i-1])%m+m)%m;
        }
        for(int i=2;i<pl;i=i+2){
            pp = ((pp + pos[i]*pos[i-1])%m+m)%m;
        }
        ans = ((ans + np + pp)%m+m)%m;
    }
    else if(pl%2==0 && nl%2==1){
        for(int i=1;i<nl-1;i=i+2){
            np = ((np + neg[i]*neg[i-1])%m+m)%m;
        }
        for(int i=1;i<pl;i=i+2){
            pp = ((pp + pos[i]*pos[i-1])%m+m)%m;
        }
        np = np+neg[nl-1];
        ans = ((np+pp)%m+m)%m;
    }
    else if(pl%2==1 && nl%2==0){
        for(int i=1;i<nl;i=i+2){
            np = ((np + neg[i]*neg[i-1])%m+m)%m;
        }
        reverse(pos.begin(), pos.end());
        for(int i=1;i<pl;i=i+2){
            pp = ((pp + pos[i]*pos[i-1])%m+m)%m;
        }
        pp = pp+pos[pl-1];
        ans = ((np+pp)%m+m)%m;        
    }
    else{
        for(int i=1;i<pl;i=i+2){
            pp = ((pp + pos[i]*pos[i-1])%m+m)%m;
        }
        for(int i=1;i<nl;i=i+2){
            np = ((np + neg[i]*neg[i-1])%m+m)%m;
        }
        ans = ((np+pp)%m+m)%m;   
    }
    return ans;
}

int main(){
    vi v = { -1, 9, 4, 5, -4, 7 };;
    cout<<findp(v)<<endl;
}