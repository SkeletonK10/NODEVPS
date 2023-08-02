#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll dp[64][128];

void solve() {
  int k, n;
  cin >> k >> n;

  for (int i = 1;i < 128;i++)
    dp[0][i] = 1;

  for (int i = 1;i <= n;i++) {
    for (int j = 1;j < 128;j++) {
      if (j != 127)
        dp[i][j] = dp[i - 1][j + 1];
      dp[i][j] += dp[i - 1][j - 1];
    }
  }
  cout << dp[n][k];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
