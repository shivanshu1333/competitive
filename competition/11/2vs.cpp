#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;

bool func(vector<long long> &v, int n, long long m, long long k){
    if(n==1)
        return true;
    for(int i=0;i<n-1;i++){
        if(v[i]+k>v[i+1]){

            m += min(v[i], v[i]+k-v[i+1]);
        }
        else
        {
            long long diff = v[i+1]-v[i]-k;
            if(diff>m){
                return false;
            }
            m -= diff;
        }
        
    }
    return true;
        
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        long long m,k;
        cin>>n>>m>>k;
        vector<long long> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        if(func(v,n,m,k))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}