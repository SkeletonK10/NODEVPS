#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  int stalNum, sightNum;
  string g;
  cin >> g >> g >> n >> g >> m;
  
  vector<int> stal(m + 1);
  vector<vector<int>> dp(n, vector<int>(m + 1, -1)), sharks(n, vector<int>(m + 1)), path(n, vector<int>(m + 1, 2));

  dp[0][0] = 0;

  cin >> stalNum >> g;
  for (int i = 0;i < stalNum;i++) {
    int h, d;
    cin >> h >> g >> g >> d >> g >> g;
    stal[d] = h;
    //cout << h << ' ' << d << endl;
  }
  
  cin >> sightNum >> g;
  for (int i = 0;i < sightNum;i++) {
    int c, d, h;
    cin >> c >> g >> d >> g >> g >> h >> g >> g;
    sharks[h][d] = c;
    //cout << c << ' ' << d << ' ' << h << endl;
  }

  for (int d = 1;d < m;d++) {
    for (int h = 0;h < n;h++) {

      if (h >= n - stal[d]) continue;

      if (( h > 0 ) && ( h - 1 < n - stal[d - 1] ) && ( dp[h - 1][d - 1] > dp[h][d] )) {
        dp[h][d] = dp[h - 1][d - 1];
        path[h][d] = -1;
      }
      if (( h < n - stal[d - 1] ) && ( dp[h][d - 1] > dp[h][d] )) {
        dp[h][d] = dp[h][d - 1];
        path[h][d] = 0;
      }
      if (( h < n - 1 ) && ( h + 1 < n - stal[d - 1] ) && ( dp[h + 1][d - 1] > dp[h][d] )) {
        dp[h][d] = dp[h + 1][d - 1];
        path[h][d] = 1;
      }
      if (dp[h][d] != -1)
        dp[h][d] += sharks[h][d];
      
      // cout << dp[h][d] << ' ';
    }
    // cout << endl;
  }
  
  int ans = -1, ansIndex = -1;
  for (int i = 0;i < n;i++) {
    if (dp[i][m - 1] > ans) {
      ansIndex = i;
      ans = dp[ansIndex][m - 1];
    }
  }

  int cur = ansIndex;
  string ansPath = "";
  for (int i = m - 1;i > 0;i--) {
    if (path[cur][i] == -1) {
      ansPath += 'v';
    }
    else if (path[cur][i] == 0) {
      ansPath += '>';
    }
    else if (path[cur][i] == 1) {
      ansPath += '^';
    }
    cur += path[cur][i];
  }

  reverse(all(ansPath));
  cout << "Saw " << ans << " sharks for sequence " << ansPath << endl;
}

int main() {
	FastIO;
	int testcase = 1;
	cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << "Case: " << tc << endl;
    solve();
	}
}
