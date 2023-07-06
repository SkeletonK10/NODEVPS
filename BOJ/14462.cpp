#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, ans = 0;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = 1;i <= n;i++)
    cin >> b[i];

  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= n;j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (abs(a[i] - b[j]) <= 4) {
        for (int k = 0;k < j;k++) {
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
