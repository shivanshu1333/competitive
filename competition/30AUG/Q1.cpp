#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(2);
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==0)
            v[0]++;
        else
            v[1]++;
    }
    cout<<min(v[0],v[1])<<endl;
        
}