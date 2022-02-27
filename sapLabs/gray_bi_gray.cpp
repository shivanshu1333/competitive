#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//backtrack n=2 0,1,3,2
// key bin i bit and i+1 bit xor is gray i bit, msb same
// gray if i bit==0 bin i bit = bin i+1 bit else negation of i+1 bit, msb same
vector<int> ans;
#define pb push_back
void q(int n, int &num){
    if(n==0) {
        ans.pb(num);
        return;
    }
    q(n-1, num);
    num = num^1<<(n-1);
    q(n-1, num);
}
vector<int> Solution::grayCode(int A){
    ans.clear();
    int num=0;
    q(A,0);
    return ans;
}

string gb(string s){
    string bi=s;
    for(int i=1;i<s.length();i++){
        if(s[i]=='0') bi[i]=bi[i-1];
        else{
            if(bi[i-1]=='0') bi[i]=='1';
            else bi[i]=='0';
        }
    }
    return bi;
}

int bi(int n){
    int x=n;
    for(int i=30;i>=0;i--){
        int ib=(n&(1<<i));
        int ipb=(n&(1<<(i+1)));
        int aa;
        if(ib==0 && ipb==0){
            aa=0;
        }
        else if(ib!=0 && ipb==0){
            aa=1;
        }
        else if(ib==0 && ipb!=0){
            aa=1;
        }
        else{
            aa=0;
        }
        if(aa==0){
            x=~(1<<(i))&x;    
        }
        else{
            x=(1<<i)|x;
        }
    }
    return x;
}

void bin_g(int n){
    int no=pow(2, n)-1;
    for(int i=0;i<=no;i++){
        ans.pb(bi(i));
    }
}

int main(){
    string gray = "1000";
    string bi = gb(gray);
    int bi_dec = stoi(bi, 0, 2);
    cout<<bi_dec<<endl;

}