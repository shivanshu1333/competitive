#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int expandAround(string a, int l, int r){
    while(l>=0  && r<=a.length() && a[l]==a[r]){
        l--;
        r++;
    }
    return r-l-1;
}

string lcs(string a){
    int s=0, e=0, n=a.length();
    int evel, oddl, len, curl=0;
    for(int i=0;i<n;i++){
        oddl=expandAround(a, i, i);
        evel=expandAround(a, i, i+1);
        len = max(oddl, evel);
        if(curl<len){
            curl=len;
            s = i-(len-1)/2;
            e = i+len/2;
        }
    }
    return a.substr(s, curl);
} 

// int expandAround(string &a, int l, int r){
//     int cnt=0;
//     while(l>=0  && r<=a.length() && a[l]==a[r]){
//         l--;
//         r++;
//         cnt++;
//     }
//     return cnt;
// }
// int countSubstrings(string a) {
//     int n=a.length();
//     int evel=0, oddl=0;
//     for(int i=0;i<n;i++){
//         oddl+=expandAround(a, i, i);
//         evel+=expandAround(a, i, i+1);
//     }
//     return oddl+evel;

int main() {
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<lcs(s)<<endl;
    }
}