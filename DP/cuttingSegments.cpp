#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void segments(vector<int> &v, int N){
    vector<int> t(N+1,-1);

    for(int j=0;j<v.size();j++){
        for(int i=1;i<t.size();i++){
            if((i-v[j])==0){
                t[i] = max(t[i],1);
            }
            else if((i-v[j])>0){
                if(t[i-v[j]]<0)
                    t[i]=max(t[i],-1);
                else if(t[i-v[j]]>0)
                    t[i]=max(t[i],(t[i-v[j]]+1));
            }
        }
    }
cout<<t[N]<<endl;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> v;
        int a, b, c;
        cin>>a>>b>>c;
        v.push_back(a);
        if(b!=a)
            v.push_back(b);
        if(c!=b && c!=a)
            v.push_back(c);
        sort(v.begin(),v.end());
        segments(v,N);
    }
}