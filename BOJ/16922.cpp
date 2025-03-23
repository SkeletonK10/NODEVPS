#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int d[4] = { 1,5,10,50 };
  int n;
  cin >> n;
  vector<vector<bool>> dp(n + 1, vector<bool>(1001));
  dp[0][0] = true;
  for (int i = 1;i <= n;i++)
    for (int j = 0;j < 1000;j++)
      for (int& k : d)
        if (dp[i - 1][j])
          dp[i][j + k] = true;
  int ans = 0;
  for (int i = 0;i <= 1000;i++)
    ans += dp[n][i] ? 1 : 0;
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
