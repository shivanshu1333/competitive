#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void getGold(vector<vector<int>> &v){
    int r = v.size(),c=v[0].size();
    vector<vector<int>> mg=v;
    for(int j=c-2;j>=0;j--){
        for(int i=0;i<r;i++){
            int a=INT_MIN,b=INT_MIN,c=INT_MIN;
            if((i-1)>=0)
                a=mg[i-1][j+1];
            b=mg[i][j+1];
            if((i+1)<=r-1)
                c=mg[i+1][j+1];
            mg[i][j]+=max(max(a,b),c);
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<r;i++)
        ans = max(ans,mg[i][0]);
    cout<<ans<<endl;
return;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int r,c;
	    cin>>r>>c;
	    vector<vector<int>> v(r,vector<int> (c));
	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            cin>>v[i][j];
        getGold(v);
	}
	return 0;
}