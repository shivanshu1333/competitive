#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void coinChange(vector<int> &s,int n){
    sort(s.begin(),s.end());
    vector<vector<int>> m(n+1,vector<int> (s.size(),0));
    for(int i=0;i<s.size();i++)
        m[0][i]=1;
    int x,y;
    for(int i=1;i<(n+1);i++){
        for(int j=0;j<s.size();j++){
            x = ((i-s[j])>=0) ? m[i-s[j]][j] : 0;
            y = (j>=1) ? m[i][j-1] : 0;
            m[i][j] = x+y;
        }
    }
    cout<<m[n][0]<<endl;
    cout<<m[n][s.size()-1]<<endl;

}

int main(){
    vector<int> s ={2};
    int target = 10;
    coinChange(s,target);
}