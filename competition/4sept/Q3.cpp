#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
#include<string>
#include<stack>
// #include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    stack<char> stk;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(!stk.empty()){
            if(c==')' && stk.top()=='('){
                stk.pop();
            }
            else
                stk.push(c);
        }
        else{
            stk.push(c);
        }
    }
    if(stk.size()==0)
        cout<<"Yes"<<endl;
    else if(stk.size()==2){
        char a = stk.top();
        stk.pop();
        if(a!=stk.top())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
        cout<<"No"<<endl;
}