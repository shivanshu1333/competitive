#include<iostream>
#include<vector>
#include<climits>
#include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
#include<queue>
#include <fstream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    // vector<int> A(n);
    vector<int> B(n-1);
    for(int i=0;i<n-1;i++){
        cin>>B[i];
        // cout<<"B[i] "<<B[i]<<" ";
    }
    // cout<<endl;
    int ans = B[0];
    // A[0] = B[0];
    if(n>1)
        ans+=B[n-2];
    // cout<<ans<<endl;
    for(int i=1;i<=n-2;i++){
        ans += min(B[i-1], B[i]);
        // cout<<min(B[i-1], B[i-2])<<endl;
        // cout<<B[i-1]<<" "<<B[i-2]<<endl;
    }
    cout<<ans<<endl;

}