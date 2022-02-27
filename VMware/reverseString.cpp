bool comp(pair<string, int> &a, pair<string, int> &b) {
    if(a.ff.length() == b.ff.length()) return a.ss < b.ss;
    return a.ff.length() < b.ff.length();
}
string arrange(string s) {
    int n = s.length();
    string te = "";
    int ind = 0;
    vector<pair<string, int>> an;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == ' ') {
            an.push_back({te, ind});
            ind++;
            te = "";
        }
        else {
            s[i] = tolower(s[i]);
            te += s[i];
        }
    }
    an.push_back({te, ind});
    sort(an.begin(), an.end(), comp);
    string aa = "";
    for(int i = 0; i < an.size() - 1; i++) {
        aa += an[i].ff;
        aa += " ";
    }
    aa += an[an.size() - 1].ff;
    aa += '.';
    aa[0] = toupper(aa[0]);
    return aa;
}