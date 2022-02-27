//"(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"
int longestDecomposition(string text) {
    int l = 0, r = text.size() - 1, hl = 0, hr = 0, p = 100007, d = 256, countr = 1, ans = 0;
    while(l < r) {
        hl = (hl*d+text[l])%p;
        hr = (countr*text[r] + hr)%p;
        countr = (countr*d)%p;
        if(hl == hr) {
            ans+=2;
            hl = 0;
            hr = 0;
            countr = 1;
        }
        l++;
        r--;
    }
    if(countr==1){
        if(l==r)
            ans++;
    } else {
        ans++;
    }
    return ans;
}