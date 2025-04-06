#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

int solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(k + 1, vector<int>(2));
  dp[0][0] = 1;
  for (int i = 0;i < n;i++) {
    for (int j = k; j >= 0;j--) {
      int t1 = dp[j][0] + dp[j][1];
      int t2 = dp[j][0];
      if (j > 0)
        t2 += dp[j - 1][1];
      dp[j][0] = t1;
      dp[j][1] = t2;
    }
  }
  return dp[k][0] + dp[k][1];
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve() << endl;
  }
}
