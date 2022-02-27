#include <bits/stdc++.h>

using namespace std;

vector <int> loadBalancing(int k, vector <int> arrival, vector <int> load) {
  int n = arrival.size();
  assert(arrival.size() == load.size()); //to check if arrival of process has load time
  set <int> busy;
  set <int> avail;
  map <int, vector <int>> upto;
  map <int, int> from;
  vector <int> total(k, 0);

  for (int i = 0; i < n; i++) { 
    avail.emplace(i);

    from[i] = arrival[i];
    int end = arrival[i] + load[i];
    upto[end].push_back(i);
  }

  for (int i = 0; i < k && i < n; i++) {
    avail.erase(i);
    busy.emplace(i);
  } 
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k;
  cin >> n;
  vector <int> arrival(n);
  for (int i = 0; i < n; i++) cin >> arrival[i];
  cin >> n;
  vector <int> load(n);
  for (int i = 0; i < n; i++) cin >> load[i];

  vector <int> ans = loadBalancing(k, arrival, load);
  for (int val : ans) cout << val << " ";
  return 0;
}