#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

bool checkk(vector<vector<bool>> &a, vector<vector<bool>> &b, int i, int j, int &cnt){
    // if((i<a.size() && j<a[0].size()) && (i<a.size() && (j+1)<a[0].size())
    //  && ((i+1)<a.size() && j<a[0].size()) && ((i+1)<a.size() && (j+1)<a[0].size())){
         bool yess = 1;

         for(int ii=0;ii<2;ii++){
             for(int jj=0;jj<2;jj++){
                //  cout<<"ai "<<ii+i<<" aj "<<jj+j<<endl;
                 if(a[ii+i][jj+j]==false){
                    yess = 0;
                    // cout<<"yes"<<endl;
                 }
             }
         }
         if(yess){
            for(int ii=0;ii<2;ii++){
             for(int jj=0;jj<2;jj++){
                 b[ii+i][jj+j]=1;
             }
         }
         cnt++;
         return 1;
        }
        // else
        // {
        //     return 0;
        // }
    return 0;
    //  }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> a(n,vector<bool> (m,0));
    vector<vector<bool>> b(n,vector<bool> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool aa;
            cin>>aa;
            a[i][j]=aa;
        }
    }
    int cnt = 0;
    vector<pair<int,int>> anss;
    // cout<<"a"<<a[2][0]<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            // cout<<"i-"<<i<<" j-"<<j<<" ch "<<checkk(a,b,i,j,cnt)<<endl;
            if(checkk(a,b,i,j,cnt))
                anss.push_back(make_pair(i+1,j+1));
            // cout<<endl;
        }
    }
    
    // cout<<anss.size()<<endl;
// for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<b[i][j]<<" ";}
//             cout<<endl;}

    if(a==b){
        cout<<cnt<<endl;
        for(int i=0;i<anss.size();i++){
            // cout<<i<<" ";
            cout<<anss[i].first<<" "<<anss[i].second<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }

}