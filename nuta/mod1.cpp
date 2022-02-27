#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
multiset<pair<int,int>> s;
int cost(){
	int ans=0;
	int sst=0;
	int prt=0;
	int prc=0;
	int ssc=0;
	for(auto r:s){
		if(r.second==1){
			++ssc;
			sst+=r.first;
			sst%=mod;
		}
		else{
			if(r.second==0){
				++prc;
				prt+=r.first;
				prt%=mod;
			}
			else
				ans=(ans+prt*sst%mod+((r.first*r.first%mod)*(ssc*prc%mod)%mod)+sst*r.first*prc%mod+prt*ssc*r.first%mod)%mod;
		}
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		s.clear();
		int P,R,S;
		cin>>P>>R>>S;
		int pro[P];
		int ram[P];
		int ssd[P];
		for(int i=0;i<P;++i){
			cin>>pro[i];
			s.insert({pro[i],0});
		}
		for(int i=0;i<R;++i){
			cin>>ram[i];
			s.insert({ram[i],2});
		}
		for(int i=0;i<S;++i){
			cin>>ssd[i];
			s.insert({ssd[i],1});
		}
		int ans = cost();
		cout<<ans<<endl;
	}
}