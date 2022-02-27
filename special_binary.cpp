// Special binary strings are binary strings with the following two properties:
// The number of 0's is equal to the number of 1's.
// Every prefix of the binary string has at least as many 1's as 0's.
// Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them.
// (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)
// At the end of any number of moves, what is the lexicographically largest resulting string possible? 
string makeLargestSpecial(string a) {
    vector<string> s;
    int n = a.size(), p = 0, g = 0;
    for(int i=0; i<n; i++){
        g += a[i] == '1' ? 1 : -1;
        if(g == 0) s.push_back("1" + makeLargestSpecial(a.substr(p+1, i-(p+1))) + "0"), p = i+1;
    }
    sort(s.begin(), s.end(), greater<string>());
    return accumulate(s.begin(), s.end(), string(""));
}