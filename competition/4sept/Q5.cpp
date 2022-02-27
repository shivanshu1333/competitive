#include<iostream>
#include<vector>
#include<climits>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    long long mv = INT_MAX;
    long long cn=0, cp=0;
    long long sum = 0;
    long long mav = INT_MIN;
    for(long long i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<0)
            cn++;
        if(v[i]>=0)
            cp++;
        mv = min(mv, v[i]);
        sum+=v[i];
        mav = max(mav, v[i]);
    }

    if(n==1){
        cout<<v[0]<<endl;
    }
    else if(cn==0){
        // cout<<mv<<endl;
        cout<<sum-2*mv<<endl;
    }
    else if(cp==0){
        cout<<-1*sum+2*mav<<endl;
    }
    else{
        sum=0;
        // mv=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=abs(v[i]);
            // mv = min(mv, abs(v[i]));
        }
        cout<<sum<<endl;
    }
}