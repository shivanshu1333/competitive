#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int find(string &A, string &B){
    int i=A.size()-1,j=i,res=0;
    while(1){
        while(i>=0 && A[i]!=B[j]){
            i--;
            res++;
        }
        if(i>=0){
            i--;
            j--;
        }
        if(i<0 || j<0)
            break;
    }
    return res;
}

int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    string A,B;
    cin>>A>>B;
    map<char, int> a, b;
    if(A.length()!=B.length()){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<A.size();i++){
            a[A[i]]++;
            b[B[i]]++;
        }
        if(a==b){
            cout<<find(A, B)<<endl;
        }
        else
            cout<<-1<<endl;
    }
}