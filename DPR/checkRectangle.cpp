#include <iostream>
#include<vector>
#include <fstream>
using namespace std;
bool allOne(vector<vector<int>> &v, int r, int c, int ri, int cj){
    int sr=ri-r;
    int sc=cj-c;
    for(int i=sr;i<=ri;i++){
        for(int j=sc;j<=cj;j++){
            // if(v[i][j]==0)
            //     return 0;
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 1;
}

void cr(vector<vector<int>> &v, int r, int c,int &m){
    if(r<0 || c<0)
        return;
    // slide();//slide and check if all 1. If all 1 then update area
    for(int i=r;i<v.size();i++){
        for(int j=c;j<v[0].size();j++)
            if(allOne(v,r,c,i,j))
                cout<<"done"<<endl;
                // m = max(m,)
    }

    cr(v,r,c-1,m);
    cr(v,r-1,c,m);
    return;
}

int main() {
	int T=1;
	// cin>>T;
    freopen("output.txt", "w", stdout);
	while(T--){
	    // int n;
	    // cin>>n;
        vector<vector<int>> v = {{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
        // for(int i=0;i<n;i++){
        //     cin>>v[i];
        // }
	    int ans = 0;
        cr(v,v.size()-1,v[0].size()-1,ans);
	    // cout<<ans<<endl;
	}
	return 0;
}