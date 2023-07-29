#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

bool dp[2501][2501];

void solve() {
  int n, s = 0;
  cin >> n;
  dp[0][0] = true;
  while (n--) {
    int a;
    cin >> a;
    s += a;
    for (int i = 2500;i >= 0;i--) {
      for (int j = 2500;j >= 0;j--) {
        if (i >= a)
          dp[i][j] |= dp[i - a][j];
        if (j >= a)
          dp[i][j] |= dp[i][j - a];
      }
    }
  }
  int ans = 0;
  for (int i = 0;i <= 2500;i++)
    for (int j = 0;j <= i;j++)
      if (dp[i][j] && j >= ( s - i - j ))
        ans = max(ans, s - i - j);
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
