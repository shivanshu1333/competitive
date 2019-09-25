#include<iostream>
#include<vector>
// #include<map>
// #include<climits>
// #include<algorithm>
// #include<string>
#include<stack>
// #include<queue>
#include<fstream>
using namespace std;

bool isSafe(int m, int n, int r, int c){
    return (r>=0) && (c>=0) && (r<m) && (c<n);
}

double dfs(int m, int n, int r, int c, int k){
    if(!isSafe(m,n,r,c))
        return 0.0;
    if(k==0)
        return 1.0;
    // double prob = 0.0;
    double ri = dfs(m, n, r, c+1, k-1);
    double l = dfs(m, n, r, c-1, k-1);
    double t = dfs(m, n, r-1, c, k-1);
    double b = dfs(m, n, r+1, c, k-1);
    return 0.25*(l+ri+t+b);
}

int main(){

    int m = 5, n = 5; 
  
    // coordinates of starting point 
    int i = 1, j = 1; 
  
    // Number of steps 
    int N = 2; 
  
    cout << "Probability is "
        << dfs(m, n, i, j, N); 
  
    return 0; 
} 