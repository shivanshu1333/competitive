#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void rod(vector<int> &v){
    vector<int> t(v.size()+1,0);
    for(int i=1;i<t.size();i++){
        int m=INT_MIN;
        for(int j=1;j<=i;j++){
            m=max(m,t[i-j]+v[j-1]);
        }
        t[i]=m;
    }
    cout<<t[v.size()]<<endl;
}

int main(){
    vector<int> v = {1,5,8,9,10,17,17,20};
    rod(v);
}