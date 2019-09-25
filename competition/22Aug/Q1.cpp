#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    // cout<<t;
    while(t--){
        int b,p,f;
        int h,c;
        cin>>b>>p>>f>>h>>c;         
        int nb = b/2;
        int ans = 0;
        if(nb==0){
            cout<<0<<endl;
            continue;
        }
        if(c>=h){
            if(nb >= f){
                ans += f*c;
                nb = nb-f;
                if(nb>p){
                    ans += h*p;
                }
                else{
                    ans += h*nb;
                }
            }
            else{
                ans += nb*c;
            }
        }
        else{
            if(nb>p){
                    ans += h*p;
                    nb = nb-p;
                if(nb>f){
                    ans+= c*f;
                }
                else{
                    ans += c*nb;
                }
            }
            else{
                ans += nb*h;
            }
        }   
        cout<<ans<<endl;
        ans = 0;
    }
}

// 6
// 15 2 3
// 5 10
// 7 5 2
// 10 12
// 1 100 100
// 100 100
// 15 2 3
// 5 10
// 7 5 2
// 10 12
// 1 100 100
// 100 100
