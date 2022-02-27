vector<string> get(string s){
    vector<string> ans;
    for(int i=0;i<s.length();i++){
        string n="";
        while(i<s.length()&&s[i]!='.'){
            n += s[i];
            i++;
        }
        ans.push_back(n);
    }
    while(ans.back()=="0") ans.pop_back();
    return ans;
}

string removeZeroes(string s){
    int i=0;
    while(i<s.size()&&s[i]=='0') i++;
    if(i==s.size()) return "";
    else return s.substr(i);
}

int compStrings(string a,string b){
    a = removeZeroes(a);
    b = removeZeroes(b);
    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return -1;
    else{
        if(a>b) return 1;
        else if(a<b) return -1;
        else if(a==b) return 0;
    }
}

int Solution::compareVersion(string A, string B) {
    vector<string> a=get(A),b=get(B);
    int x = min(a.size(),b.size());
    int i;
    for(i=0;i<x;i++){
        int cmp = compStrings(a[i],b[i]);
        if(cmp!=0) return cmp;
    }
    if(i!=a.size()){
        return 1;
    }else if(i!=b.size()){
        return -1;
    }else{
        return 0;
    }
}

