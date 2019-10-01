#include<bits/stdc++.h>
#define ff first
#define ss second
#define d double
using namespace std;
double pi = 3.1415926535897932384;
// cout<< fixed <<setprecision(3)<<pi<<endl;

void circleIntersectionArea(d x1, d x2, d r1, d y1, d y2, d r2, d c1c2){
        d r = r1;
        d R = r2;
        d cd = c1c2;
        if(R < r){
            r = r2;
            R = r1;
        }
        d part1 = r*r*acos((cd*cd + r*r - R*R)/(2*cd*r));
        d part2 = R*R*acos((cd*cd + R*R - r*r)/(2*cd*R));
        d part3 = 0.5*pow(((-cd+r+R)*(cd+r-R)*(cd-r+R)*(cd+r+R)), 0.5);
        d area = part1 + part2 - part3;
        d ans = floor(area);
        long long int fans= ans;
        cout<<fans<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        d x1, x2, r1, y1, y2, r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        d c1c2 = pow(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)), 0.5);
        if(c1c2>=(r1+r2))
            cout<<0<<endl;
        else if((c1c2+min(r1,r2))<=max(r1,r2)){
            d anss = pi*min(r1, r2)*min(r1, r2);
            long long int aans = floor(anss);
            cout<<aans<<endl;
        }
        else
            circleIntersectionArea( x1,  x2,  r1,  y1,  y2,  r2,  c1c2);
    }
}