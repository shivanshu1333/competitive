#include <iostream>
using namespace std;

int main() {
    int Tn;
    cin>>Tn;
    if(Tn==0||Tn==1)
        cout<<Tn<<endl;
    if(Tn==2)
        cout<<1<<endl;
    int tmp,p,pp;
    p=1;pp=1;
    for(int i=2;i<Tn;i++){
        tmp=p;
        p+=pp;
        pp=tmp;
    }
    cout<<p<<endl;
}