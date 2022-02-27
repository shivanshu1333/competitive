#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct Node{
    int val;
    Node *l;
    Node *r;
    Node(int x) : val(x), l(NULL), r(NULL){}
};
int i;
Node* cons(vi in, vi pr, int l, int r){
    if(l>r) return NULL;
    Node *head = new Node(pr[i]);
    int ind=-1;
    for(int k=l;k<=r;k++)
        if(pr[i]==in[k]){
           ind=k;
           break;
        }
    i++;
    head->l = cons(in, pr, l, ind-1);
    head->r = cons(in, pr, ind+1, r);
    return head;
}

void post(Node* rt){
    if(rt==NULL) return;
    post(rt->l);
    post(rt->r);
    cout<<rt->val<<" ";
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vi pr(n);
        for(int i=0;i<n;i++) cin>>pr[i];
        vi in=pr;
        sort(in.begin(), in.end());
        i=0;
        Node *h=cons(in, pr, 0, in.size()-1);
        post(h);
        cout<<endl;
    }
	return 0;
}