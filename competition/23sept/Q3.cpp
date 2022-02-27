class Solution {
public:
    #define f first
    #define s second
    string removeKdigits(string num, int k) {
    if(num.length()==k)
        return "0";
    multimap<int, vector<pair<int,int>>> m;
    // vector<pair<int, int>> dp(num.length());
        vector<pair<int, int>> lis(num.length(), {0, 0});
        lis[num.length()-1]={0, num.length()-1};
        for(int i=num.length()-2;i>=0;i--){
            for(int j=num.length()-1;j>i;j--){
                if(num[i]-'0'>num[j]-'0'){
                    lis[i].f=max(lis[i].f,lis[j].f+1);
                    lis[i].s=i;
                    
                }
                else{
                    lis[i].f=lis[i].f;
                    lis[i].s=i;
                }
            }
        }
        
    for(int i=0;i<lis.size();i++){
        m[lis[i].f].push_back({(num[lis[i].s]-'0'), lis[i].s});
    }
    
    // map<int, vector<pair<int,int>>> ::iterator it;
        for(auto it=m.begin();it!=m.end();it++){
            sort(it->second.begin(), it->second.end());
            // for(int i=0;i<it->s.size();i++)
            //         cout<<it->s[i].f<<" "<<it->s[i].s<<" ";
            // cout<<endl;
        }
    vector<int> excl;
        int cntk=0;
        bool br=0;
    for(auto it=m.rbegin();it!=m.rend();it++){
        cout<<it->s.size()<<endl;
        cout<<it->s[0].f<<endl;
        for(int ind=it->s.size()-1;ind>=0;ind--){
            excl.push_back(it->s[ind].s);
            // cntk++;
            if(excl.size()==k){
                br=1;
                break;
            }
        }
        if(br==1)
            break;
    }
    // for(int i=0;i<excl.size();i++)
            // cout<<excl[i]<<endl;
        string ans="";
        // int ind=0;
        // for(int i=0;i<num.size();i++){
        //     if(i==excl[ind]) ind++;
        //     else{
        //         if(ans.length()==0){
        //             if(num[i]!='0')
        //                 ans+=num[i];
        //         }
        //         else
        //             ans+=num[i];
        //     }
        // }
        if(ans.length()==0)
            return "0";
        return ans;
        
    }
};

// 0321100
// 321100