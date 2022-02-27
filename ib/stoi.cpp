int Solution::atoi(const string A){
    stringstream ss;
    ss<<A;
    long long i;
    ss>>i;
    if(i<INT_MIN)
        i=INT_MIN;
    if(i>INT_MAX)
        i=INT_MAX;
    return i;
}
