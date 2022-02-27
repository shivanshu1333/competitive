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
    while(t--){
        unsigned long long int n, m;
        cin>>n>>m;
        unsigned long long int cnt;
        // if(n%m==0)
        //     cout<<"yes"<<endl;
        // if(n%m==0 && n>1 && m!=1){
        //     cnt = (n-1)/m;
        // }
        // else
            cnt = n/m;
        // cout<<"cnt"<<cnt<<endl;
        unsigned long long int ans = 0;
        // cout<<cnt<<"n"<<endl;
        m=m%10;
        // cout<<m<<endl;
        // cout<<"cnt"<<cnt<<endl;
        unsigned long long ss = 0;
        for(int i=1;i<=10;i++)
            ss += (m*i)%10;

        // // if(cnt>1000000){

        // // }
        // unsigned long long tt = ss;
        unsigned long long cntt = cnt;
        cntt = cnt/10;
        ans+= ss*cntt;
        
        for(unsigned long long i=1;i<=(cnt-cntt*10);i++){
            ans += (m*i)%10;
        }
        // for(unsigned long long int i=1;i<=n;i++){
        //     if(i%m == 0)
        //     ans += (i%10);
        // }
        cout<<ans<<endl;
    }
    
}