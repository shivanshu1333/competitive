    int peakIndexInMountainArray(vector<int>& A) {
        int lo=0, hi=A.size()-1;
        while(lo<hi){
            int m = lo+(hi-lo)/2;
            if(A[m]<A[m+1])
                lo = m+1;
            else
                hi = m;
        }
        return lo;
    }