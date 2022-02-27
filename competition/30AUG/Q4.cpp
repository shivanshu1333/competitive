#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> v(2*100000+1);
    int no;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin>>no;
        cnt = 0;
        while(no>0){
            v[no].push_back(cnt);
            cnt++;
            no/=2;
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<v.size();i++){
        if(v[i].size()>=k){
            sort(v[i].begin(), v[i].end());
                int vs = 0;
                for(int j=0;j<k;j++)
                    vs += v[i][j];
                ans = min(ans, vs);
        }
    }
    cout<<ans<<endl;
}