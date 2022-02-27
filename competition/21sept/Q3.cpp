#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
#define s second
using namespace std;
int main(){
    fast;
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int x5,y5,x6,y6;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
    pair<int,int> tbl,tbr,ttl,ttr;
    pair<int,int> lbl,lbr,ltl,ltr;
    pair<int,int> rbl,rbr,rtl,rtr;
    tbl={x1,y1};tbr={x2,y1};ttl={x1,y2};ttr={x2,y2};
    if(x3<x5){
        lbl={x3,y3};lbr={x4,y3};ltl={x3,y4};ltr={x4,y4};
        rbl={x5,y5};rbr={x6,y5};rtl={x5,y6};rtr={x6,y6};
    }
    else{
        rbl={x3,y3};rbr={x4,y3};rtl={x3,y4};rtr={x4,y4};
        lbl={x5,y5};lbr={x6,y5};ltl={x5,y6};ltr={x6,y6};
    }

    if(tbr.f<=lbl.f)
        cout<<"YES"<<endl;
    else if(tbl.f>=rbr.f)
        cout<<"YES"<<endl;
    else{
        if(tbl.f>=lbl.f && tbr.f<=lbr.f && ttl.s<=ltl.s && tbl.s>=lbl.s)
            cout<<"NO"<<endl;
        else if(tbl.f>=rbl.f && tbr.f<=rbr.f && ttl.s<=rtl.s && tbl.s>=rbl.s)
            cout<<"NO"<<endl;
        else if(lbr.f>=rbl.f){
            int lb, rb, bb, tb;
            lb = lbl.f;
            rb=rbr.f;
            bb=max(lbl.s, rbl.s);
            tb=min(ltl.s, rtl.s);
            if(tbl.f>=lb && tbr.f<=rb && ttl.s<=tb && tbl.s>=bb)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}