int Solution::isNumber(const string S) {
    const char *s = S.c_str();
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '\0') return false;
    if (s[i] == '+' || s[i] == '-') i++;
    int dig, pts;
    for (dig=0, pts=0; (s[i] <= '9' && s[i] >= '0') || s[i]=='.'; i++) {
        if (s[i] == '.') {
            pts++;
        } else {
            dig++;
        }
    }
    if (pts > 1 || dig < 1 || s[i - 1] == '.')
        return false;
    if(s[i] == 'e') {
        i++;
        if (s[i] == '+' || s[i] == '-') i++;
        dig = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            i++;
            dig++;
        }
        if (dig < 1)
            return false;
    }
    while (s[i] == ' ') {
        i++;
    }
    return s[i] == '\0';
}