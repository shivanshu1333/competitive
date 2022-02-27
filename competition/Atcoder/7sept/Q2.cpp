#include<iostream>
#include<vector>
// #include<climits>
// #include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>
// #include <fstream>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> A(n+1);
    vector<int> B(n+1);
    vector<int> C(n);   
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
        cin>>B[i];
    for(int i=1;i<n;i++)
        cin>>C[i];
    int ans = 0;
    int prev = -1;
    for(int i=1;i<=n;i++){
        ans+=B[A[i]];
        if(prev == A[i]-1)
            ans+=C[A[i]-1];
        prev = A[i];
    }
    cout<<ans<<endl;

}