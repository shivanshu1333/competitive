#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(vector<int> &v){
    int n = v.size();
    vector<int> lis(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    return *max_element(lis.begin(),lis.end());
}

int main(){
    vector<int> v = {1,3,4,6,5,4,2};
    int ans = lis(v);
    cout<<ans<<endl;
}