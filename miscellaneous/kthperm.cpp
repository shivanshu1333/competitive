#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "HHHVVVV";
    int k=0;
    do{
        k++;
        if(k==4) break;
    }while(next_permutation(s.begin(), s.end()));
    cout<<s<<endl;
}