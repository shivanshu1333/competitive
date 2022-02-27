#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
#define ll long long

vector<int> slidingMin(vector<int> &A, int w) {
    int n = A.size();
    vector<int> B;
    if (n < w) return B;
    B.resize(n - w + 1);
    deque<int> Q;
    for (int i = 0; i < w; i++) {
        while (!Q.empty() && A[i] <= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = w; i < n; i++) {
        B[i - w] = A[Q.front()];
        while (!Q.empty() && A[i] <= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i - w)
            Q.pop_front();
        Q.push_back(i);
    }
    B[n - w] = A[Q.front()];
    return B;
}

int main(){
    vi sl = {1,2,3,1,2};
    int w=3;
    vi ans = slidingMin(sl, w);
    cout<<*max_element(ans.begin(), ans.end()); 

}