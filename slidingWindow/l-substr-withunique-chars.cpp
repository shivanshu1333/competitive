#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lus(string a){
    int l=0,r=0;
    int mc=0;
    int cc=0;
    unordered_map<char, int> m;
    while(r<a.length()){
        if(m.count(a[r])==0){
            m[a[r]]=r;
        }
        else{
            mc=max(mc, r-l);
            l=m[a[r]]+1;
            m.clear();
            m[a[l]]=l;
            r=l;
        }
        r++;
    }
    mc=max(mc, r-l);
    return mc;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        string a;
        cin>>a;
        cout<<lus(a)<<endl;
    }
}