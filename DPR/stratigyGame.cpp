#include <iostream>
#include<vector>
using namespace std;

int os(vector<int> &v, int i, int j){
    if(abs(i-j)<=1)
        return max(v[i],v[j]);
    int x = v[i]+min(os(v,i+2,j),os(v,i+1,j-1));
    int y = v[j]+min(os(v,i+1,j-1),os(v,i,j-2));
    return max(x,y);
    
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
	    int ans = os(v,0,v.size()-1);
	    cout<<ans<<endl;
	}
	return 0;
}