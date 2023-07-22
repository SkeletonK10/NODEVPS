#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> field(n + 1);
  int dp[11][1024] = { 0 };
  for (int i = 1;i <= n;i++)
    cin >> field[i];

  int ans = 0;
  for (int i = 1;i <= n;i++) {
    for (int j = 0; j < ( 1 << m );j++) {
      bool rowJudge = true;
      for (int k = 0;k < m - 1;k++)
        if (( j & ( 1 << k ) ) && ( j & ( 1 << ( k + 1 ) ) ))
          rowJudge = false;
      for (int k = 0;k < m;k++)
        if (( j & ( 1 << k ) ) && field[i][k] == 'x')
          rowJudge = false;

      if (!rowJudge)
        continue;

      int cnt = 0;
      for (int k = 0;k < m;k++)
        cnt += ( j & ( 1 << k ) ) ? 1 : 0;
      
      for (int k = 0;k < ( 1 << m );k++) {
        bool judge = true;
        for (int l = 0;l < m - 1;l++)
          if (( j & ( 1 << l ) ) && ( k & ( 1 << ( l + 1 ) ) ))
            judge = false;
        for (int l = 1;l < m;l++)
          if (( j & ( 1 << l ) ) && ( k & ( 1 << ( l - 1 ) ) ))
            judge = false;
        if (judge) {
          dp[i][j] = max(dp[i][j], dp[i - 1][k]);
        }
      }
      dp[i][j] += cnt;
      ans = max(ans, dp[i][j]);
    }
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
