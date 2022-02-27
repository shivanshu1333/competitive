    #include<bits/stdc++.h>
    using namespace std;
    typedef unsigned long long ll;
     
    int main(){
        // freopen("i.txt", "r", stdin);
        // freopen("o.txt", "w", stdout);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int s;
            bool tn=0;
            bool sn=0;
            unordered_map<int, int> m;
            while(n--){
                cin>>s;
                if(s<2048){
                    m[s]++;
                    sn=1;
                }
                if(s==2048){
                    tn=1;
                }
            }
            if(tn==1)
                cout<<"YES"<<endl;
            else if(sn==1){
                tn=0;
                // sn=1;
                bool cnt=1;
                unordered_map<int, int> :: iterator it;
                while(tn==0 && cnt==1){
                    cnt=0;
                    for(it=m.begin();it!=m.end();it++){
                        if(it->first==2048) tn=1;
                        if(it->second >=2){
                            it->second-=2;
                            m[2*it->first]++;
                            if(2*it->first) tn=1;
                        }
                        if(it->second >=2)
                            cnt=1;
                    }
                }
                if(tn==1)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
    }