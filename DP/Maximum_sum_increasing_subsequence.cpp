#include<iostream>
#include<vector>
// #include<string>
// #include<climits>
// #include<algorithm>
using namespace std;

void lis(vector<int> &v){
    vector<int> dp1(v.size(),1);
    vector<int> dp2(v.size(),1);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<=i;j++){
            if(v[j]<v[i]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    // reverse(v.begin(), v.end());
    for(int i=v.size()-1;i>=0;i--){
        for(int j=v.size()-1;j>=i;j--){
            if(v[j]<v[i]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<v.size();i++)
        ans = max(dp1[i]=dp2[j], ans);
    cout<<ans-1<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        lis(v);
    }
}