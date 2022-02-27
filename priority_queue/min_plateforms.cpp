#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
// 3 methods, 1 prefix sum - least time O(n);
// 2 priority queue O(nlogn)
// 3 merge sort method 
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int t;
        vector<pair<int, int>> a(N), d(N);
        for(int i=0;i<N;i++){
            cin>>t;
            a[i]={t, 1};
        }
        for(int i=0;i<N;i++){
            cin>>t;
            d[i]={t+1, -1};
        }
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        //using queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
            q.push(a[0]);
            q.push(d[0]);
        int i=1,j=1;
        int ans=0;
        int tmp=0;
        while(!q.empty()){
            tmp+=q.top().s;
            q.pop();
            ans = max(ans, tmp);
            if(i<a.size()){
                q.push(a[i]);
                i++;
            }
            if(j<d.size()){
                q.push(d[j]);
                j++;
            }
        }
        cout<<ans<<endl;
    }
}
{
        int N;
        cin>>N;
        vector<int> a(N), d(N);
        for(int i=0;i<N;i++) cin>>a[i];
        for(int i=0;i<N;i++) cin>>d[i];
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        int i=1, j=0;
        int pl=1,ans=1;
        while(i<a.size()){
            if(a[i]<=d[j]){
                pl++;
                i++;
                ans = max(ans, pl);
            }
            else{
                pl--;
                j++;
            }
        }
        cout<<ans<<endl;
}

{
            memset(a, 0, sizeof(a));
        int N;
        cin>>N;
        int t;
        int in=0;
        for(int i=0;i<N;i++){
            cin>>t;
            in = max(t, in);
            a[t]++;
        }
        for(int i=0;i<N;i++){
            cin>>t;
            in = max(t, in);
            a[t+1]--;
        }
        int ans=0;
        for(int i=1;i<=in;i++){
            a[i]+=a[i-1];
            ans = max(ans, a[i]);
        }
        cout<<ans<<endl;
}