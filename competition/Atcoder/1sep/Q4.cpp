#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

using namespace std;

// long long int pe(long long int n, long long int k) 
// { 
//     long long int P[n + 1][k + 1]; 
//     for (long long int i = 0; i <= n; i++) 
//     { 
//         for (long long int j = 0; j <= min(i, k); j++) 
//         { 
//             if (j == 0) 
//                 P[i][j] = 1; 
//             else
//                 P[i][j] = P[i - 1][j] +  
//                           (j * P[i - 1][j - 1]); 
//             P[i][j + 1] = 0; 
//         } 
//     } 
//     long long int ans = 0;
//     // cout<<P[5][2]<<endl;
//     for(long long int i=1;i<=n;i++) {
//         ans += i%P[n][i];
//         // cout<<"this "<<P[n][i]<<endl;
//         cout<<i%P[n][i]<<endl;
//     }
//     return ans;
// } 

int main(){
    unsigned long long int n;
    cin>>n;
    unsigned long long int a, b;
    if(n%2==0){
        a = n/2;
        b = n-1;
    }
    else{
        a = (n-1)/2;
        b=n;
    }
        
    cout<<a*b<<endl;
}