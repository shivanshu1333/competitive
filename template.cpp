#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
// // cin.ignore(numeric_limits<streamsize>::max(),'\n');
int find(vector<int> &pa ,int i){
    while(pa[i] != i){
        pa[i] = pa[pa[i]]; 
        i = pa[i]; 
    }
return i;
}
void unio(vector<int> &pa, int A, int B){
    int root_A = find(pa, A);
    int root_B = find(pa, B);
    if(root_A<root_B){
        pa[root_A] = pa[root_B];
    }
    else
        pa[root_B] = pa[root_A];
}
// ////Segment tree
// int n, t[4*MAXN];
// void build(int a[], int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }
// int sum(int v, int tl, int tr, int l, int r) {
//     if (l > r) 
//         return 0;
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return sum(v*2, tl, tm, l, min(r, tm))
//            + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
// }
// void update(int v, int tl, int tr, int pos, int new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }
// ///modpow, (x^y)%p in O(log y)
// int power(int x, unsigned int y, int p) {
//     int res = 1;  
//     x = x % p;
//     while (y > 0) {
//         if (y & 1) 
//             res = (res*x) % p; 
//         y = y>>1;
//         x = (x*x) % p;   
//     } 
//     return res; 
// } 

// #include<bits/stdc++.h>
// #define ll unsigned long long
// #define mem(a, b) memset(a, b, sizeof(a))
// #define F(i,s,e) for(auto i=s;i<e;i++)
// #define pi acos(-1)
// #define v vector
// #define ss size()
// #define l length()
// #define f first
// #define s second
// typedef vector<vector<int>> vvi;
// typedef vector<int> vi;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1,-1, 0,  0};
// int rk[] = {-2, -2, -1, 1, 2, 2, 1, -1};
// int ck[] = {-1, 1, 2, 2, 1, -1, -2, -2};
// int dx[] = {1, 0, -1,  0, 1,  1, -1, -1};
// int dy[] = {0, 1,  0, -1, 1, -1,  1, -1};
// using namespace std;

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int main(){
    // ListNode p =ListNode(5);
    // cout<<p.val;
    string s = "10";
    cout<<stoi(s, 0, 2)<<endl;
    int x = 0;
    x=~x;
    cout<<x<<endl;
}

//list
	list<int> list1; 
	list<int>::iterator it = list1.begin(); 
	list1.insert(it, 1);
  	it = list1.begin(); 
  	advance(it, 1);
    list1.insert(it, 2);
  	it = list1.begin(); 
	advance(it, 2); 
	list1.insert(it, 3); 
	for (list<int>::iterator i = list1.begin(); i != list1.end(); i++) 
		cout << *i << " "; 