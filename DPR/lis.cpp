#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_map> 

using namespace std;

int lis_util(vector<int> &v, int n, int &maxl){
    cout<<"For n = "<<n<<" : ";
    for(int j=0;j<n;j++)
        cout<<v[j]<<" ";
    cout<<endl<<"maxl = "<<maxl<<endl;
    if(n==1)
        return 1;
    int res,mtn=1;
    for(int i=1;i<n;i++){
        res = lis_util(v,i,maxl);
        if(v[i-1]<v[n-1] && res+1>mtn)
            mtn=res+1;
    }
    if(maxl<mtn)
        maxl=mtn;
    return mtn;
}

int lis(vector<int> &v, int n){
    int maxl = 1;
    lis_util(v,n,maxl);
    return maxl;
}

int main(){
    vector<int> v = {3,10,2,1,20};
    int n = v.size();
    int ans = lis(v,n);
    cout<<ans<<endl;
}