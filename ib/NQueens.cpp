#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(vector<string> &v, int row, int col){
    for(int i=col;i>=0;i--){
        if(v[row][i]=='Q')
        return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]=='Q')
        return false;
    }
    for(int i=row,j=col;i<v.size()&&j>=0;i++,j--){
        if(v[i][j]=='Q')
        return false;
    }
    return true;
}

bool solnq(vector<string> &v, int col, vector<vector<string>> &ans){
    if(col == v.size()){
        ans.push_back(v);
        return true;
    }
    for(int i=0;i<v.size();i++){
        if(isSafe(v,i,col)){
            v[i][col] = 'Q';
            solnq(v,col+1,ans);
            v[i][col] = '.';
        }
    }
    return false;
}

int main(){
    // int n = 4;

    // string s(n,'.');
    // vector<string> v(n,s);
    // vector<vector<string>> ans;
    // solnq(v,0,ans);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++)
    //     cout<<ans[i][j]<<" ";
    // }
    // cout<<endl;

    vector<int> v = {1,2,3,4,5};
    int i = 3;
    v.erase(v.begin()+i);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}