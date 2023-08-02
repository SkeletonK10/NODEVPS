#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll dp[31][31];

ll solve() {
  int m, n;
  cin >> m >> n;
  vector<string> s(m + 1);
  vector<int> mn(m + 1, 0), mx(m + 1, n);
  for (int i = 1;i <= m;i++)
    cin >> s[i];

  for (int i = 1;i <= m;i++) {
    for (int j = 0;j < n;j++) {
      if (s[i][j] == 'R')
        mx[i] = min(mx[i], j);
      if (s[i][j] == 'B')
        mn[i] = j + 1;
    }
  }

  dp[0][n] = 1;

  for (int i = 1;i <= m;i++) {
    dp[i][0] = ( mn[i] == 0 ) ? dp[i - 1][n] : 0;
    for (int j = 1;j <= n;j++) {
      dp[i][j] = dp[i][j - 1];
      if (mn[i] <= j && j <= mx[i])
        dp[i][j] += dp[i - 1][n] - dp[i - 1][j - 1];
    }
  }
  return dp[m][n];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    cout << solve();
  }
}
