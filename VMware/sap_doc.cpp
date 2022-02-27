7
1
2
12
5
6
30
32

7
15
10
10
10
10
15
10
// finds the pair with minimum distance between them
// verified against CGL_5_A AOJ
//closest_distance.cpp

#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
};

Point result1, result2;
double bestDistance;

double euclideanDistance(Point a, Point b)  {
  double X = a.x - b.x, Y = a.y - b.y;
  return sqrt(X * X + Y * Y);
}

// comparison first done by y coordinate, then by x coordinate
bool lesser(Point a, Point b) {
  if (a.y < b.y) {
    return true;
  }
  if (a.y > b.y) {
    return false;
  }
  return a.x < b.x;
}

void merge(Point* a, Point* aux, int lo, int mid, int hi)   {
  int i, j, k;
  for (k = lo; k <= hi; k++) {
    aux[k] = a[k];
  }

  i = lo; j = mid + 1; k = lo;
  while (i <= mid && j <= hi) {
    a[k++] = lesser(aux[i], aux[j]) ? aux[i++] : aux[j++];      
  }

  // Copy the rest of the left side of the array into the target array
  while (i <= mid) {
    a[k++] = aux[i++];
  }
}

double closestPair(Point* pointsByX, Point* pointsByY, Point* aux, int lo, int hi) {
  if(hi <= lo) {
    return numeric_limits<double>::infinity();
  }

  int mid = lo + (hi - lo) / 2;
  double delta = closestPair(pointsByX, pointsByY, aux, lo, mid);
  double dist = closestPair(pointsByX, pointsByY, aux, mid + 1, hi);
  if (dist < delta) {
    delta = dist;
  }

  merge(pointsByY, aux, lo, mid, hi);

  int m = 0, i, j;
  for (i = lo; i <= hi; i++) {
    if (abs(pointsByY[i].x - pointsByX[mid].x) < delta) {
      aux[m++] = pointsByY[i];
    }
  }
  double distance;
  for (i = 0; i < m; i++) {
    for (j = i + 1; j < m && (aux[j].y - aux[i].y < delta); j++) {
      distance = euclideanDistance(aux[i], aux[j]);
      if (distance < delta) {
        delta = distance;
        if (delta < bestDistance) {
          bestDistance = delta;
          result1 = aux[i];
          result2 = aux[j];
        }
      }
    }
  }
  return delta;
}

bool comp(Point a, Point b)  {
  return a.x < b.x;
}

int main()  {

  int n, i;
  Point *points, *pointsByY, *aux;

  // Enter the number of points in the plane
  scanf("%d", &n);    
  points = new Point[n];

  // Enter n points (x, y)
  for (i = 0; i < n; i++) { 
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  if (n <= 1) return 0;

  sort(points, points + n, comp);
  pointsByY = new Point[n];
  for (i = 0; i < n; i++) {
    pointsByY[i] = points[i];
  }
  aux = new Point[n];

  bestDistance = numeric_limits<double>::infinity();
  closestPair(points, pointsByY, aux, 0, n - 1);
  //printf("%lf %lf\n", result1.x, result1.y);
  //printf("%lf %lf\n", result2.x, result2.y);
  printf("%.12lf\n", bestDistance);
  return 0;
}

//count_palindromes.cpp

#include <bits/stdc++.h>

using namespace std;

int solve(const string &str) {
  int n = str.length();
  vector <vector <bool>> dp(n, vector <bool>(n, false));
  //1 length
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }
  //2 length
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    dp[i][j] = (str[i] == str[j]);
  }
  //3 length onwards
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (str[i] == str[j]) {
        dp[i][j] = dp[i + 1][j - 1];
      } else {
        dp[i][j] = false;
      }
    } 
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt += dp[i][j];
    }
  } 

  return cnt;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  int ans = solve(str);
  cout << ans << endl;
  return 0;
}

//load_balancing.cpp
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
    int end = arrival[i] + laod[i];
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

//load_balancing.cpp

#include <bits/stdc++.h>

using namespace std;

const int pinf = (1U << 31) - 1;

vector <vector <int>> dp;

int solveUtil(int l, int h, const string &str) {
  if (l == h) return 0;   //1 length
  if (l + 1 == h) return str[l] != str[h]; //2 length

  if (dp[l][h] != -1) return dp[l][h];

  int ans = pinf;
  if (str[l] == str[h]) {
    ans = solveUtil(l + 1, h - 1, str);
  } else {
    int left = solveUtil(l + 1, h, str);
    int right = solveUtil(l, h - 1, str);
    ans = 1 + min(left, right);
  }

  return dp[l][h] = ans;
} 

int solve(const string &str) {
  dp.clear();
  int n = str.length();
  dp.resize(n);
  for (int i = 0; i < n; i++) {
    dp[i].resize(n);
    fill(dp[i].begin(), dp[i].end(), -1);
  }

  int ans = solveUtil(0, n - 1, str);
  return ans;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  int ans = solve(str);
  cout << ans << endl;
  return 0;
}

//pair_sum.cpp
#include <bits/stdc++.h>

using namespace std;

bool solve(int sum, vector <int> arr) {
  int n = arr.size();
  unordered_set <int> seen;
  for (int i = 0; i < n; i++) {
    int req = sum - arr[i];
    if (seen.find(req) != seen.end()) {
      return true;
    }
    seen.insert(arr[i]); 
  } 

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, sum;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> sum;
  bool ans = solve(sum, arr);
  cout << ans << endl;
  return 0;
}
// longest string chain
#include <bits/stdc++.h>
using namespace std;

vector <vector <bool>> look;

bool successor(const string &a, const string &b) {
  int na = a.length();
  int nb = b.length();
  if (na + 1 != nb) return false;
  int cnt = 0;
  for (int i = 0, j = 0; i < na && j < nb; ) {
    if (a[i] != b[j]) {
      cnt++;
      j++;
      continue;
    }
    i++; j++;
  }
  return cnt <= 1;
}

bool comp(const string &a, const string &b) {
  return a.length() < b.length();
}
vector <vector <int>> dp;

class Solution {
public:
  int solveUtil(int idx, int last, int n) {
    if (idx == n) return 0;
    if (dp[idx][last] != -1) return dp[idx][last];
    int ans = 0;
    if (look[idx][last]) {
      ans = max(ans, 1 + solveUtil(idx + 1, idx, n));
    }
    ans = max(ans, solveUtil(idx + 1, last, n));
    return dp[idx][last] = ans;
  }
  int longestStrChain(vector<string>& words) {
    look.clear();
    dp.clear();

    sort(words.begin(), words.end(), comp);
    int n = words.size();

    look.resize(n);
    for (int i = 0; i < n; i++) {
      look[i].resize(n);
      fill(look[i].begin(), look[i].end(), false);
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        look[j][i] = successor(words[i], words[j]);
      }
    }

    dp.resize(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(n);
      fill(dp[i].begin(), dp[i].end(), -1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, 1 + solveUtil(i + 1, i, n));
    }
    return ans;
  }
};

int main() {
  vector <string> words = {"a","b","ba","bca","bda","bdca"};
  cout << Solution().longestStrChain(words) << endl;
  return 0;
}