#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int dp[100005][5][5];

void solve() {
  int dist[5][5] = {
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
  };
  fill(&dp[0][0][0], &dp[100004][4][4], INF);
  dp[0][0][0] = 0;
  int n = 0;
  while (++n) {
    int cmd;
    cin >> cmd;
    if (!cmd) {
      int ans = INF;
      for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
          ans = min(ans, dp[n - 1][i][j]);
      cout << ans;
      return;
    }

    for (int i = 0;i < 5;i++) {
      for (int j = 0;j < 5;j++) {
        if (i == j) continue;
        for (int k = 0;k < 5;k++) {
          if (i == cmd)
            dp[n][i][j] = min(dp[n][i][j], dp[n - 1][k][j] + dist[k][i]);
          else if (j == cmd)
            dp[n][i][j] = min(dp[n][i][j], dp[n - 1][i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
