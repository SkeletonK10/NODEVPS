#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e6 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int ac[51][51];
int dp[51][51][51][51];

// dp[i][j][k][l]:
// i amusement center visited
// last visited j-th amusement center
// on (k, l)

void solve() {
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1;i <= c;i++) {
    int x, y;
    cin >> x >> y;
    ac[x][y] = i;
  }

  if (ac[1][1])
    dp[1][ac[1][1]][1][1] = 1;
  else
    dp[0][0][0][1] = 1;

  for (int i = 0;i <= c;i++) {
    for (int j = i;j <= c;j++) {
      for (int k = 1;k <= n;k++) {
        for (int l = 1;l <= m;l++) {
          if (i != 0 && ac[k][l] == j) {
            for (int M = i - 1;M < j;M++)
              dp[i][j][k][l] += dp[i - 1][M][k - 1][l] + dp[i - 1][M][k][l - 1];
          }
          else if(ac[k][l] == 0) {
            dp[i][j][k][l] = dp[i][j][k - 1][l] + dp[i][j][k][l - 1];
          }
          dp[i][j][k][l] %= MOD;
          // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << endl;
        }
      }
    }
  }

  for (int i = 0;i <= c;i++) {
    int ans = 0;
    for (int j = i;j <= c;j++) {
      ans += dp[i][j][n][m];
    }
    cout << ans % MOD << ' ';
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
