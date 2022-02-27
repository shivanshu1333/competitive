//"AB" (1 2) or "L" (12). A->1
int numDecodings(string s) {
      int n = s.size();
      if(!n || s[0] == '0')
          return 0;
      int f0 = 1, f1 = 1, f2, i;
      for(i = 2; i <= n; ++i)
      {
           f2 = (int)(s[i-1] != '0')*f1 + (int)((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] < '7'))*f0;
           f0 = f1;
           f1 = f2;
      }
    return f1;
}