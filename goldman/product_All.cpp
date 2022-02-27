class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        vector<int> ans(v.size(), 0);
        ans[0]=1;
        for(int i=1;i<v.size();i++){
            ans[i] = ans[i-1]*v[i-1];
        }
        int r=1;
        for(int i=v.size()-1;i>=0;i--){
            ans[i]=ans[i]*r;
            r = r*v[i];
        }
        return ans;
    }
};