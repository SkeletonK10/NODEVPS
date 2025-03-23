#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int dst[100001][11], dp[100001][11];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int j = 1;j <= m;j++)
    for (int i = 1;i <= n;i++)
      cin >> dst[i][j];
  for (int i = 1;i <= m;i++)
    dp[1][i] = dst[1][i];

  for (int i = 2;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      for (int k = 1;k <= m;k++) {
        int e = ( j != k ) ? dst[i][j] : ( dst[i][j] / 2 );
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + e);
      }
    }
  }
  int ans = 0;
  for (int i = 1;i <= m;i++)
    ans = max(ans, dp[n][i]);

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
