#include<iostream>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef double dd;
#define pb push_back

int main(){
    int input1, input2;
    vector<vector<int>> input3;
    cin>>input1>>input2;
    for(int i=0;i<input2;i++){
        int x,y;
        cin>>x>>y;
        input3.pb({x,y});
    }
    char *ans = del(input1, input2, input3);
    cout<<ans<<endl;
}