#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int m, int r){
    int i=0, j=0, k=l;
    int nl=m-l+1;
    int nr=r-m;
    int a[nl], b[nr];
    for(int f=0;f<nl;f++) a[f]=v[l+f];
    for(int f=0;f<nl;f++) b[f]=v[m+1+f];
    while(i<nl && j<nr){
        if(a[i]<b[j]){
            v[k]=a[i];
            i++;
        }
        else{
            v[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        v[k]=a[i];
        i++;
        k++;
    }
    while(j<nr){
        v[k]=b[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int l, int r){
    if(l<r){
        int m = l - (l-r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    vector<int> v = {4,6,9,8,7,2,0};
    mergeSort(v, 0, 6);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}