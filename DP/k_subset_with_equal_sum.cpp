#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool rec(vector<int> &grp, int i, vector<int> &v, int s){
    if(i<0) return 1;
    int val=v[i];
    i--;
    for(int j=0;j<grp.size();j++){
        if(grp[j]+val<=s){
            grp[j]+=val;
            if(rec(grp, i, v, s)==1) return 1;
            grp[j]-=val;
        }
    }
    return 0;
}

bool isKPartitionPossible(int A[], int N, int K){
    int s=0;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        v[i]=A[i];
        s+=A[i];
    }
    int k=K;
    if(s%k!=0) return 0;
    s/=k;
    sort(v.begin(), v.end());
    if(v[N-1]>s) return 0;
    int i=N-1;
    while(v[i]==s && i>=0){
        k--;
        i--;
    }
    vector<int> grp(k,0);
    return rec(grp, i, v, s);
}


int main(){
    
}