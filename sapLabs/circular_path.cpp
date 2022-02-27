#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


bool cir(string &s){
    int x=0, y=0;
    int dir=0;
    
    for(int i=0;i<s.length();i++){
        char cc=s[i];
        if(dir==0){
            if(cc=='G') y--;
            if(cc=='L') dir = ((dir+1)%4+4)%4;
            if(cc=='R') dir = ((dir-1)%4+4)%4;
        }
        else if(dir==1){
            if(cc=='G') x++;
            if(cc=='L') dir = ((dir+1)%4+4)%4;
            if(cc=='R') dir = ((dir-1)%4+4)%4;
        }
        else if(dir==2){
            if(cc=='G') y++;
            if(cc=='L') dir = ((dir+1)%4+4)%4;
            if(cc=='R') dir = ((dir-1)%4+4)%4;
        }
        else if(dir==3){
            if(cc=='G') x--;
            if(cc=='L') dir = ((dir+1)%4+4)%4;
            if(cc=='R') dir = ((dir-1)%4+4)%4;
        }
    }
    if(x==0 && y==0) return 1;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        bool c = cir(s);
        if(c) cout<<"Circular"<<endl;
        else cout<<"Not Circular"<<endl;
    }
}
