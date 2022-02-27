#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

void isRect(vector<int> &v,int rs){
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
        m[v[i]]++;
    vector<int> vec;
    unordered_map<int,int> :: iterator it; 
    for(it=m.begin();it!=m.end();it++){
        if((it->second % 2)!=0){
            cout<<"NO"<<endl;
            return;
        }
        int l = (it->second)/2;
        for(int i=0;i<l;i++)
            vec.push_back(it->first);
    }
    sort(vec.begin(),vec.end());
    int pro = vec[0]*vec[vec.size()-1];
    for(int i=1;i<(vec.size())/2;i++){
        if(vec[i]*vec[vec.size()-1-i]!=pro){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> v(4*n);
        for(int i=0;i<4*n;i++)
            cin>>v[i];
        // sort(v.begin(),v.end());
        isRect(v,n);
    }
}