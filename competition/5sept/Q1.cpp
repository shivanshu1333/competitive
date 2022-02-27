#include<iostream>
#include<vector>
#include<climits>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

// #include <fstream>

using namespace std;

int main(){ 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
    int t;
    cin>>t;
    while(t--){
        int s,i,e;
        cin>>s>>i>>e;
        if(s+e<=i){
            cout<<0<<endl;
        }
        else{
            if((s+e-i)%2==0){
                int beta = (s+e-i)/2;
                if(beta<=e){
                    cout<<beta<<endl;
                }
                else{
                    cout<<e+1<<endl;
                }
            }
            else{
                int beta = (s+e-i)/2;
                if(beta<e){
                    cout<<beta+1<<endl;
                }
                else{
                    cout<<e+1<<endl;
                }
            }
        }
    }      
}   