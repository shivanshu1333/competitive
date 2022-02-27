#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 1e8+1
#define eps 0.000000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>//usage rand<long long>()
T rand() {
    return uniform_int_distribution<T>()(rng);
}

// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
//////////////
#define all(x) x.begin(),x.end()
#define S second
#define F first
#define sz(x) ((long long)x.size())
#define int long long  
#define f80 __float128
#define pii pair<int,int>
/////////////


signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t)
	{
		--t;
		int a,b,c;
		cin>>a>>b>>c;
		int pr[a];
		int ra[b];
		int ss[c];
		multiset<pair<int,int>> s;
		for(int i=0;i<a;++i)
		{
			cin>>pr[i];
			s.insert({pr[i],0});
		}
		for(int i=0;i<b;++i)
		{
			cin>>ra[i];
			s.insert({ra[i],2});
		}
		for(int i=0;i<c;++i)
		{
			cin>>ss[i];
			s.insert({ss[i],1});
		}
		int ans=0;
		int sst=0;
		int prt=0;
		int prc=0;
		int ssc=0;
		int mo=1000000007;
		for(auto r:s)
		{
			if(r.second==1){
				++ssc;
				sst+=r.first;
				sst%=mo;
			}
			else{
				if(r.second==0){
					++prc;
					prt+=r.first;
					prt%=mo;
				}
				else
				{
					ans=(ans+prt*sst%mo+((r.first*r.first%mo)*(ssc*prc%mo)%mo)+sst*r.first*prc%mo+prt*ssc*r.first%mo)%mo;
				}
			}
		}
		cout<<ans<<"\n";
	}
}