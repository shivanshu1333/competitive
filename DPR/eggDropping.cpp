#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int eggDrop(int n, int k){
    if(n==1)
        return k;
    if(k==1 || k==0)
        return k;
    int min = INT_MAX, res;

    for(int i=1;i<=k;i++){
        res = max(eggDrop(n-1,i-1),eggDrop(n,k-i));
        if(res<min)
            min = res;
    }
    return min+1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        cout<<eggDrop(n,k)<<endl;
    }
}