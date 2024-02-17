#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int furthestBuilding(vector<int>& h, int b, int l) {
    int diff = 0;
    int i = 0;
    priority_queue<int> pq;
    for(i=0;i<h.size()-1;i++){
        diff = h[i+1] - h[i];
        if(diff <= 0) continue;
        b -= diff;
        pq.push(diff);
        if(b<0){
            int top = pq.top();
            pq.pop();
            b+=top;
            l--;
        }
        if (l<0) break;
    }
    return i;
}

int main(){
    vector<int> h{ 14,3,19,3 };
    int b = 17, l = 0;
    cout<<furthestBuilding(h, b, l)<<endl;
}