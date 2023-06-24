#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e4;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int dp[101][4][4];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1);
  for (int i = 0;i < k;i++) {
    int t1, t2;
    cin >> t1 >> t2;
    v[t1] = t2;
  }

  if (v[1]) {
    dp[1][0][v[1]] = 1;
  }
  else {
    dp[1][0][1] = 1;
    dp[1][0][2] = 1;
    dp[1][0][3] = 1;
  }

  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= 3;j++) {
      for (int k = 1;k <= 3;k++) {
        for (int l = 0;l <= 3;l++) {
          if (j == k && k == l)
            continue;
          dp[i][j][k] += dp[i - 1][l][j];
          dp[i][j][k] %= MOD;
        }
        if (v[i] != 0 && k != v[i])
          dp[i][j][k] = 0;
      }
    }
  }

  int ans = 0;
  for (int i = 1;i <= 3;i++)
    for (int j = 1;j <= 3;j++)
      ans += dp[n][i][j];
  cout << ans % MOD;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
