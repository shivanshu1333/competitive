#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0, r=n-1;
    int cnt=0;
    while(l<r){

        if(v[l]%2==1){

            if(v[r]%2==0){
                cnt++;
                r--;
                l++;
            }
            else{
                r--;
            }

        }
        else{
            while(l<r && (v[l]%2==0))
                l++;
        }

    }
    cout<<cnt<<endl;
}