#include<bits/stdc++.h>
using namespace std;

int preced(char ch) {
   if(ch == '+' || ch == '-') return 1;
   else if(ch == '*' || ch == '/') return 2;
   else if(ch == '^') return 3;
   else return 0;
}

string inToPost(string st ) {
   stack<char> stk;
   stk.push('#');
   string postfix = "";

   for(int i=0; i<st.length(); i++) {
      if(isalnum(st[i]))
         postfix += st[i];
      else if(st[i] == '(')
         stk.push('(');
      else if(st[i] == '^')
         stk.push('^');
      else if(st[i] == ')') {
         while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top();
            stk.pop();
         }
         stk.pop();
      }else {
         if(preced(st[i]) > preced(stk.top()))
            stk.push(st[i]);
         else {
            while(stk.top() != '#' && preced(st[i]) <= preced(stk.top())) {
               postfix += stk.top();
               stk.pop();
            }
            stk.push(st[i]);
         }
      }
   }

   while(stk.top() != '#') {
      postfix += stk.top();
      stk.pop();
   }

   return postfix;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        string st;
        cin>>st;
        cout<<inToPost(st)<<endl;
    }
}