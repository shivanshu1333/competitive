#include <iostream>
#include<string>
#include<vector>
using namespace std;

int min3(int a, int b, int c){
    return min(min(a,b),c);
}

int editDist(string a, string b, int n, int m){
    if(n==0 || m==0)
        return abs(n-m);
    if(a[n-1]==b[m-1])
        return editDist(a,b,n-1,n-1);

    //converting string 1 to string 2
    return 1+ min3 (editDist(a,b,n,m-1),//insert
                    editDist(a,b,n-1,m),//remove
                    editDist(a,b,n-1,m-1));//replace
}

int main(){
    string a = "sunday";
    string b = "saturday";
    int ans = editDist(a,b,a.length(),b.length());
    cout<<ans<<endl;
}