vector<pair<int, int>> te;
for(int i = 0; i < a.size(); i++) {
    te.push_back({a[i] + b[i], a[i]});
}
sort(te.begin(), te.end());
int ans = 1;
int fi = te[0].first;
for(int i = 1; i < te.size(); i++) {
    if(te[i].second >= fi) {
        ans++;
        fi = te[i].first;
    } 
}
return ans;