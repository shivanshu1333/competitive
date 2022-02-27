#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector>
#include <utility>
using namespace std;

int main(){
    unsigned long long n,m;
    int T;
    cin>>n>>m>>T;
    while(T--){
        pair<unsigned long long,unsigned long long> a,b;
        cin>>a.first>>a.second>>b.first>>b.second;
        unsigned long long gc = __gcd(n,m);
        unsigned long long as,bs;
        as=n/gc;
        bs=m/gc;
        if(a.first>b.first){
            swap(a,b);
        if(((a.second-1)/as)==((b.second-1)/bs))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }
        else if(a.first==b.first){
        unsigned long long ns;
            if(a.first==1)
                ns=n/gc;
            else
                ns=m/gc;
            if(((a.second-1)/ns)==((b.second-1)/ns))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else{
        if(((a.second-1)/as)==((b.second-1)/bs))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }
    }
}