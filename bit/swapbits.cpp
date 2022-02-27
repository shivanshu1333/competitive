// #include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<climits>
#define ui unsigned int
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;

int main(){
    ui x;
    cin>>x;
    ui p1,p2,n;
    cin>>p1>>p2>>n;
    ui mask=(1<<n)-1;
    ui set_p1 = x>>p1 & mask;
    ui set_p2 = x>>p2 & mask;
    ui xor_swap_mask = set_p1^set_p2;
    ui final_mask = xor_swap_mask<<p1 | xor_swap_mask<<p2;
    ui ans = x^final_mask;
    cout<<ans<<endl;
}