#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool partition(vector<int> &v,int m, int tar){
    if(tar==0)
        return 1;
    if(tar<0 || m<=0)
        return 0;
    return partition(v,m-1,tar) || partition(v,m-1,tar-v[m]);

}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];;
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        if(sum%2!=0){ cout<<"NO"<<endl; return 0;}
        else if(partition(v,v.size()-1,sum/2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}