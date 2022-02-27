using namespace std;

int getUmbrellas(int n, vector <int> p) {
  sort(p.begin(), p.end(), greater<int>());
  int total = 0;
  for (int i = 0; i < (int) p.size(); i++) {
    total += p[i];
    if (total >= n) return i + 1;
  }

  //impossible
  return -1; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  cin >> m;
  vector <int> p;
  for (int i = 0; i < m; i++) cin >> p[i];
  int ans = getUmbrellas(n, p);
  cout << ans << endl;
  return 0;
}