#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

// 4
// 6 3
// aaabbc

bool comp(pair<int, int> a, pair<int, int> b){
    return a.s<b.s;
}

struct CompareDist{
    bool operator()(pair<int,int> a,pair<int,int> b) {
        return a.s>b.s;
    }
};

queue< , , comp > q;

pair<int, pair<int, int>>
vector<pair<int, pair<int, int>>>

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist > q;
    q.push({2,4});
    q.push({1000,-23});
    q.push({39,231});
    q.push({433,-39});
    q.push({-238,3000});
    q.push({-23233,-3232});
    q.push({321,89});
    while(!q.empty()){
        pair<int,int> tp = q.top();
        q.pop();
        cout<<tp.f<<" "<<tp.s<<endl;
    }
    return 0;
}
