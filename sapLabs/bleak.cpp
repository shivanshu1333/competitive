#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int msb = 0;
    for(int i = 0;i<32;i++){
        if(n&(1<<i))
        msb = i;
    }
    ++msb;
    for(int i = msb ;i>=0;i--){
        if(setbits(n-i)==i){
            cout<<"Supported Number! and supported by : "<<n-i<<endl;
            return 0;
        }
    }
    cout<<"Bleak Number!"<<endl;
    return 0;
}