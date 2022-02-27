#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> tmp=v;

	    next_permutation(v.begin(), v.end());
        if(tmp==v)
            sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
	}
	return 0;
}