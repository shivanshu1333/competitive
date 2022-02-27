#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
#include<string>
// #include<stack>
// #include<queue>

using namespace std;

int main(){
     long long n;
     long long d, e;
    cin>>n>>d>>e;
    e = 5*e;
    // vector<   long long> dp(n);
    long long m = min(e, d);
    long long ma = max(e, d);
    // cout<<ma<<" "<<m<<endl;
    long long ans1 = n%ma;
    ans1 = ans1%m;
    long long ans2 = n%m;
    long long ans = min(ans1, ans2);
    ans1 = n%m;
    ans1 = ans1%ma;
    ans = min(ans, ans1);
    ans1 = n%ma;
    ans = min(ans, ans1);
    cout<<ans<<endl;
}