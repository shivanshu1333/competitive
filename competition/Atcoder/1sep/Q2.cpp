#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

using namespace std;

int main(){
    int A,B;
    cin>>A>>B;
    int nos = A;
    int cnt = 1;
    if(B==1){
        cout<<0<<endl;
    }
    else{
    while(nos<B){
        nos = nos-1 + A;
        cnt++;
    }
    cout<<cnt<<endl;  
    }  
}