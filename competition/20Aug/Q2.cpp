#include<algorithm>
#include <iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <queue> 
using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;

    int min = 0;
int cnt = 0;
int i=1;
    while(cnt<l){
        // min += i;
        // cout<<i<<" ";
        cnt++;
        min += i;  
        i=i*2;      
    }
    // cout<<cnt<<" "<<min;
    min += n-cnt;
    cout<<min<<" ";

    cnt = 0;
    i=1;
    int maxx = 0;
    int g = 1;
    while(cnt<r){
         cnt++;
        maxx += i;
        g = max(g,i);
        i=i*2;
        // cout<<maxx<<" ";
        
    }
    // cout<<g<<endl;
    // cout<<maxx<<endl;
    // cout<<g<<endl;
    maxx += (n-cnt)*g;

    cout<<maxx<<endl;
}