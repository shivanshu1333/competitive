#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define rp pop_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;

//permutation next_permutation, functions, swap, vis.
// using next_permutation
//initially sort the given list

void func(vvi &ans, vi &A){
    do{
        ans.pb(A);
    }while(next_permutation(A.begin(), A.end()));
}
// using vis Array
void func(vvi &ans, vi &A, vi &v, vb &vis){
    if(v.size()==A.size()){
        ans.pb(v);
        return;
    }

    for(int i=0;i<A.size();i++){
        if(!vis[i]){
            vis[i]=1;
            v.pb(A[i]);
            func(ans, A, v, vis);
            v.rp();
            vis[i]=0;
        }
    }
}
// using swap
void func(vvi &ans, vi &A, int s){
    if(s==A.size()){
        ans.pb(A);
        return;
    }
    for(int i=s;i<A.size();i++){
        swap(A[s], A[i]);
        func(ans, A, s+1);
        swap(A[s], A[i]);
    }
}

int ans;
vi av;

int cost(vvi &g, vi &c){
    int cst=0;
    cst+=g[0][c[0]];
    for(int i=1;i<c.size();i++){
        cst+=g[c[i-1]][c[i]];
    }
    cst+=g[0][c[c.size()-1]];
    return cst;
}

void find(vvi &g, vi &c){
    do{
        int cst = cost(g,c);
        if(cst<ans){
            ans = cst;
            av=c;
        }
    }while(next_permutation(c.begin(), c.end()));
}

int main(){
    vvi g = {
                {0, 4, 1, 3},
                {4, 0, 2, 1},
                {1, 2, 0, 5},
                {3, 1, 5, 0}
            };
    ans = INT_MAX;
    vi c = {1, 2 ,3};
    find(g, c);
    cout<<ans<<endl;
    cout<<"1->";
    for(int i=0;i<av.size();i++){
        cout<<av[i]+1<<"->";
    }
    cout<<"1"<<endl;
}

