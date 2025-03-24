#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

const int INF = 987654321;

using namespace std;

// dp[i][j]: i번째 열, j만큼 채워짐
// j == 0: field[i][0] 채워짐
// j == 1: field[i][1] 채워짐
// j == 2: field[i][0], field[i][1] 모두 채워짐
int dp[10001][3];
int field[10001][2];

void dp_construct(int n, int w, int init = 1) {
  for (int i = init;i <= n;i++) {
    dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
    if (field[i - 1][0] + field[i][0] <= w)
      dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
    // cout << dp[i][0] << ' ';

    dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
    if (field[i - 1][1] + field[i][1] <= w)
      dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
    // cout << dp[i][1] << ' ';

    dp[i][2] = min({ dp[i][2], dp[i][0] + 1, dp[i][1] + 1 });
    if (field[i][0] + field[i][1] <= w)
      dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);
    if (
      ( i >= 2 ) &&
      ( field[i - 1][0] + field[i][0] <= w ) &&
      ( field[i - 1][1] + field[i][1] <= w ))
      dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
    // cout << dp[i][2] << endl;

  }
  // cout << endl;
}

void solve() {
  int n, w, ans = INF;
  cin >> n >> w;
  for (int i = 0;i < 2;i++)
    for (int j = 1;j <= n;j++)
      cin >> field[j][i];
  if (n == 10000) {
  }
  fill(&dp[0][0], &dp[10000][2] + 1, INF);
  dp[0][2] = 0;
  dp_construct(n, w);
  ans = min(ans, dp[n][2]);

  if (field[1][0] + field[n][0] <= w) {
    fill(&dp[0][0], &dp[10000][2] + 1, INF);
    dp[1][0] = 1;
    dp_construct(n, w);
    ans = min(ans, dp[n][1]);
  }

  if (field[1][1] + field[n][1] <= w) {
    fill(&dp[0][0], &dp[10000][2] + 1, INF);
    dp[1][1] = 1;
    dp_construct(n, w);
    ans = min(ans, dp[n][0]);
  }

  if (n >= 2 && field[1][0] + field[n][0] <= w && field[1][1] + field[n][1] <= w) {
    fill(&dp[0][0], &dp[10000][2] + 1, INF);
    dp[1][2] = 2;
    dp_construct(n, w);
    ans = min(ans, dp[n - 1][2]);
  }
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}