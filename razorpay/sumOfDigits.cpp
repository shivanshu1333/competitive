#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int helper(int n, vi &v){
    if(n<10) return n*(n+1)/2;
    int d = (int) log10(n);
    int p = (int)ceil(pow(10, d));
    int msd = n/p;
    return (msd*v[d]+(msd*(msd-1)/2)*p+msd*(1+n%p)+helper(n%p, v));
}

int sumD(int n){
    int d = (int)log10(n);
    vi v(d+1);
    v[0] = 0;
    v[1]=45;
    for(int i=2;i<=d;i++)
        v[i] = v[i-1]*10 + 45*(int)ceil(pow(10, i-1));
    return helper(n, v);
}

int main(){
    int n = 328;
    cout<<"sumOfDig from to n"<<sumD(n);
}