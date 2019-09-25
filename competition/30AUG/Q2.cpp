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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int ans = 0;
        int minv = v[n-1];
        for(int i=n-2;i>=0;i--){
            if(v[i]>minv)
                ans++;
            minv = min(v[i],minv);
        }
        cout<<ans<<endl;
    }
    
}