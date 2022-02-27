//(i<j<k) && (a[i]>a[j]>a[k])
#include<bits/stdc++.h>
using namespace std;
int getInvCount(vector<int> &v, int n){
	int cnt = 0;
    for(int i=1;i<n-1;i++){
        int sm=0;
        for(int j=i+1;j<n;j++)
            if(v[i]>v[j]) sm++;
        int big=0;
        for(int j=i-1;j>=0;j--)
            if(v[i]<v[j]) big++;
        cnt +=sm*big;
    }
    return cnt;
}
int main(){
	vector<int> v = {8, 4, 2, 1};
    int n=v.size();
	cout << "Inversion Count : " << getInvCount(v, n);
	return 0;
}