#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_map> 

using namespace std;

int lis(vector<int> &v, int n){
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    return *max_element(lis,lis+n);
}

int main(){
    vector<int> v = {3,10,2,1,20};
    int n = v.size();
    int ans = lis(v,n);
    cout<<ans<<endl;
}