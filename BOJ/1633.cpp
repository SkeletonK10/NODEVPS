#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int dp[16][16];

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  int a, b;
  while (cin >> a >> b) {
    for (int i = 15;i >= 0;i--) {
      for (int j = 15;j >= 0;j--) {
        if (i > 0 && dp[i - 1][j] != -1)
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + a);
        if (j > 0 && dp[i][j - 1] != -1)
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + b);
      }
    }
  }
  cout << dp[15][15];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
