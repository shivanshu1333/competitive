string Solution::addBinary(string a, string b) {
    string ans = "";
    int ansLen = 0, carry = 0, sum;
    int i = (int)a.length() - 1, j = (int)b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += (a[i] - '0');
        if (j >= 0) sum += (b[j] - '0');
        ans.push_back((char)('0' + sum % 2));
        carry = sum / 2;
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}