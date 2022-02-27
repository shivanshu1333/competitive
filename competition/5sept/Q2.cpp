#include<iostream>
#include<vector>
#include<climits>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>

// #include <fstream>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
    int t;
    cin>>t;
    while(t--){
        int n, h;
        cin>>n>>h;
        vector<pair<int, int>> v;
        int ch,rh;
        int ma = INT_MIN;
        int mac = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>ch>>rh;
            mac = max(mac, ch);
            if(ch>rh){
                v.push_back({ch,rh});
                ma = max(ma, ch-rh);
                // cout<<"ma "<<mac<<endl;
            }
        }
        // cout<<v.size()<<endl;
        if(h==0)
            cout<<0<<endl;
        else if(mac>=h)
            cout<<1<<endl;
        else if(v.size()==0)
            cout<<-1<<endl;
        else{
            for(int i=0;i<v.size();i++){
                if(ma == (v[i].first-v[i].second)){
                    ch = v[i].first;
                    rh = v[i].second;
                }
            }
            // cout<<ch<<" "<<rh<<" yo"<<endl;
            int x = h-mac;
            int y = ch-rh;
            if(x%y == 0)
                cout<<(x/y)+1<<endl;
            else
                cout<<(x/y)+2<<endl;
        }
    }
}