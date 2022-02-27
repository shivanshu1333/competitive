//we can delete a subset b1b2b3...bk from the   array if 2^b1 + 2^b2 + …..2^bk = 2^x
int minBin(vector<int> a) {
	const int L = 1E6; // max possible value of ai
	vector<int> cnt(L + 30);
	for (int ai : a) cnt[ai]++;

	int ans = (cnt[0] & 1);
	for (int i = 1; i < L + 30; i++) {
		cnt[i] += cnt[i - 1] >> 1;
		if (cnt[i] & 1) ans++;
	}
	return ans;
}