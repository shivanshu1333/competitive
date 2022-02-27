#include<iostream>
#include<vector>
#include<map>
// #include<climits>
// #include<map>
#include<algorithm>
#include<string>
// #include<stack>
// #include<queue>
#include <fstream>
using namespace std;


int distanceBetweenBusStops(vector<int>& di, int s, int d) {
    int distc = 0;
    int distac = 0;
    int n=di.size();
    if(d==s)
        return 0;
    else if(d>s){
        int l=s;
        while(l<d){
            distc+=di[l];
            l++;
        }
        l=s;
        while(l!=d){
            distac+=di[(n+(l-1)%n))%n];
            l--;
            if(l<0)
                l+=di.size();
        }
        return min(distc, distac);
    }
    else if(d<s){
        int l=s;
        while(l!=d){
            distac +=di[(n+(l-1)%n))%n];
            l--; 
        }
        l=s;
        while(l!=d){
            distc += di[l];
            l++;
            if(l>=di.size())
                l-=di.size(); 
            return min(distc, distac);
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

}