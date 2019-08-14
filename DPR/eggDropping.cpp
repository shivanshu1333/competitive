#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int eggDrop(int n, int k){
    if(k==0 || k==1)
        return k;
    if(n==1)
        return k;
    int min = INT_MAX, res;

    for(int x=1;x<=k;x++){
        res = max(eggDrop(n-1,x-1),eggDrop(n,k-x));
        if(res<min)
            min = res;
    }
return min+1;
}

int main(){
    int egg = 2;
    int flooe = 10;
    cout<<eggDrop(2,10)<<endl;
}