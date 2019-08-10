#include <iostream>
#include<vector>
using namespace std;

int stairDist(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    return stairDist(n-1)+stairDist(n-2)+stairDist(n-3);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int ans = stairDist(n);
	    cout<<ans<<endl;
	}
	return 0;
}