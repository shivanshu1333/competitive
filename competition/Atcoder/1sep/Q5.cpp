#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
// #include<string>
#include<stack>
// #include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a;
    vector<queue<int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin>>a;
            v[i].push(a);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i].size()>0){
            int top = v[i].front();
            if(v[v[i].front()].size()==0){
                cout<<-1<<endl;
            }
            else{
                if()
            }

        }
            if(v[i].front()==v[v[i].front()])
    }
}