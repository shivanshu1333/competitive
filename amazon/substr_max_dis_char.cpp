void minWindow(string s) {
    int n=s.length();
    vector<int>a(256,0);
    int c = 0;
    for(int i=0;i<n;i++){
        if(a[s[i]] == 0){
            c++;
            a[s[i]]=1;
        }
    }
    
    int len = n,l=0,r=0;
    
    for(int i =0 ; i < n;i++){
        a[s[i]]--;
        if(a[s[i]] ==0)c--;
        
        while(c==0 ){
            if(len > i-r+1){
                len = i-r+1;
            }
            a[s[r]]++;
            if(a[s[r]]==1)c++;
            r++;
        }
    }
    cout<<len<<endl;
}