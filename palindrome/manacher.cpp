#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
 
    vector< vector<int> > d(2);
    d[0].resize(n);
    d[1].resize(n);
    for (int p = 0; p < 2; ++p) {
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r ? 0 : min (d[p][l + r - i] - p, r - i)) + 1;
            while (i + k - 1 < n && i - k + p >= 0 && s[i + k - 1] == s[i - k + p]) ++k;
            d[p][i] = --k;
            if (i + k > r)
                l = i - k + p, r = i + k - 1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<d[1][i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<d[1][i]<<" ";

    // for(int i=0;i<n;i++){
    //     cout<<s.substr(i+1-d[1][i], 2*d[1][i]-1)<<endl;
    // }
    // int m1 = 0;
    // int m2 = 0;
    // for (int i = 1; i < n; ++i) {
    //     if (d[1][m1] < d[1][i]) {
    //         m1 = i;
    //     }
    //     if (d[0][m2] < d[0][i]) {
    //         m2 = i;
    //     }
    // }
    // if (d[1][m1] > d[0][m2]) {
    //     cout << s.substr(m1 - d[1][m1] + 1, d[1][m1] * 2 - 1);
    // } else {
    //     cout << s.substr(m2 - d[0][m2], d[0][m2] * 2);
    // }
    return 0;
}