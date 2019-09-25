#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int i=1,j=1,k=1;;
        long long dp[N+1];
        dp[0]=1;
        dp[1]=1;
        int in = 2;
        while(in<=N){
            long long a = 2*dp[i];
            long long b = 3*dp[j];
            long long c = 5*dp[k];
            long long push = (min(min(a,b),c));
            if(a==push)
                i++;
            if(b==push)
                j++;
            if(c==push)
                k++;
            dp[in]=push;
            in++;
        }
        // for(int i=0;i<N+1;i++)
            cout<<dp[N]<<endl;
    }
}