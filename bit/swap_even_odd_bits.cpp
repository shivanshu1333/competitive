// #include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<climits>
#define ui unsigned int
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;

int main(){
    ui a;
    cin>>a;
    ui even_mask = 0;
    ui odd_mask = 0;
    for(int i=0;i<32;i+=2){
        odd_mask = odd_mask | (1<<i);
    }
    for(int i=1;i<32;i+=2){
        even_mask = even_mask | (1<<i);
    }
    ui even_bits = even_mask&a; //0xAAAAAAAA as A in hex is 10 in binary
    ui odd_bits = odd_mask&a;   //0x55555555 as 5 in hex is 01 in binary
    // even_bits>>1;
    // odd_bits<<1;
    ui ans = even_bits>>1 | odd_bits<<1;
    cout<<ans<<endl;
}