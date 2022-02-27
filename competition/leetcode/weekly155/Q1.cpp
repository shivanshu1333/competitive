class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> v;
        sort(a.begin(), a.end());
        int md = INT_MAX;
        for(int i=0;i<a.size()-1;i++){
            md = min(a[i+1]-a[i], md);
        }
        for(in ti=0;i<a.size()-1;i++){
            if((a[i+1]-a[i])==md)
                v.push_back({a[i], a[i+1]});
        }
        return v;
    }
};