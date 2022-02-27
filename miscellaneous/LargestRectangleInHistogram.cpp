#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& hist) {
    stack<int> stk;
    int area=0;
    int i=0;
    for(i=0;i<hist.size();i++){
        if(stk.empty() || hist[i]>=hist[stk.top()]){
            stk.push(i);
        }
        else{
            while(!stk.empty() && hist[i]<hist[stk.top()]){
                int top=stk.top();
                stk.pop();
                if(stk.empty()) 
                    area = max(area, hist[top]*(i));
                else
                    area = max(area, hist[top]*(i-1-stk.top()));
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        int top=stk.top();
        stk.pop();
        if(stk.empty()) 
            area = max(area, hist[top]*(i));
        else
            area = max(area, hist[top]*(i-1-stk.top()));        
    }
    return area;        
}

int main(){
    vector<int> v = {3, 1, 3, 3, 1, 3, 2};
    cout<<largestRectangleArea(v)<<endl;
}