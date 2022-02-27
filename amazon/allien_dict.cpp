#include<bits/stdc++.h>
using namespace std;
string order;

string printOrder(string s[], int N, int k){
    vector<vector<int>> g(k);
    vector<int> ind(k, 0);
    for(int i=0;i<N-1;i++){
        int j=0;
        while(j<s[i].length() && j<s[i+1].length()){
            if(s[i][j]!=s[i+1][j]){
                char ch1 = s[i+1][j];
                char ch2 = s[i][j];
                g[ch2-'a'].push_back(ch1-'a');
                ind[ch1-'a']++;
                break;
            }
            j++;
        }
    }
    string str;
    queue<int> q;
    for(int i=0;i<k;i++){
        if(ind[i]==0){
            q.push(i);
            ind[i] = -1;
        }
    }
    int u = 0;
    while(!q.empty()){
        u = q.front();
        char ch = u + 'a';
        str += ch;
        q.pop();
        for(int v = 0;v<g[u].size();v++){
            ind[g[u][v]]--;
            if(ind[g[u][v]]==0){
                q.push(g[u][v]);
                ind[g[u][v]] = -1;
            }
        }
    }
    return str;
}


bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}