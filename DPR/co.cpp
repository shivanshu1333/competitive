#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    int neg = 0;
    int ze = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<0)
            neg++;
        if(v[i]==0)
            ze++;
    }
    long long ans = 0;
    // cout<<"n"<<ze<<" "<<neg<<endl;
    
    if(neg%2 == 0){
        for(int i=0;i<n;i++){
            if(v[i]<0)
                ans += abs(-1 - v[i]);
            else
                ans += abs(1 - v[i]);
        }
        cout<<ans<<endl;
        return 0;
    }

    else{
        for(int i=0;i<n;i++){
            if(v[i]<0)
                ans += abs(-1 - v[i]);

            else{
                ans += abs(1 - v[i]);
            }
        }
        if(ze == 0)
            ans += 2;

            cout<<ans<<endl;
            return 0;
    }
    

}