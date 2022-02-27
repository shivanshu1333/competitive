#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int ans=0;
        for(int l=1;l*(l+1)<2*N;l++){
            if((N-(l*(l+1)/2))>0 && (N-(l*(l+1)/2))%(l+1)==0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}