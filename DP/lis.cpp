//n^2
int lis(vector<int> &v){
    int n = v.size();
    vector<int> lis(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    return *max_element(lis.begin(),lis.end());
}

int main(){
    vector<int> v = {1,3,4,6,5,4,2};
    int ans = lis(v);
    cout<<ans<<endl;
}
// nlogn
int CeilIndex(std::vector<int>& v, int l, int r, int key){
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}
int LongestIncreasingSubsequenceLength(std::vector<int>& v){
	if (v.size() == 0)
		return 0;
	vector<int> tail(v.size(), 0);
	int length = 1;
	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < tail[0])
			tail[0] = v[i];
		else if (v[i] > tail[length - 1])
			tail[length++] = v[i];
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
	}
	return length;
}
