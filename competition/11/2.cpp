#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;

bool func(vector<long long> &v, int n, long long m, long long k){
    if(n==1)
        return true;
    for(int i=0;i<n-1;i++){
        long long dif = abs(v[i+1]-v[i]);
        // cout<<"dif "<<dif<<endl;
        if(dif>k){
            if(v[i]>v[i+1]){
                
            }
            else if(v[i]<v[i+1]){
                if((v[i]+m+k)>=(v[i+1]) ){
                    // cout<<"hey"<<endl;
                    m = m-(v[i+1]-v[i]-k);
                    // cout<<"(k-v[i]) "<<(k-v[i])<<endl;
                    // cout<<"m "<<m<<endl;
                    }
                else
                    return false;
            }
        }
        else if(dif<k){
            if(v[i]>v[i+1]){
                m+=(v[i]-v[i+1]);
            }
            else if(v[i]<v[i+1]){
                m+= k - v[i+1]+v[i];
            }
        }
        else if(dif==k){
            if(v[i]>v[i+1])
                m+=k;
            // cout<<"m "<<m<<endl;
            // cout<<k<<endl;
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