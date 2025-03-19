#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  ll dp[10001] = {}, dp_temp[10001] = {};
  int n;
  cin >> n;
  int h0;
  cin >> h0; // very first input
  if (h0 < 1)
    dp[0] = 1;
  for (int i = 1;i < n;i++) {
    int h;
    cin >> h;
    if (h != -1) {
      dp_temp[h] += dp[h];
      if (h > 0)
        dp_temp[h] += dp[h - 1];
      if (h < 10000)
        dp_temp[h] += dp[h + 1];
      dp_temp[h] %= MOD;
    }
    else {
      for (int j = 0;j <= 10000;j++) {
        dp_temp[j] += dp[j];
        if (j > 0)
          dp_temp[j] += dp[j - 1];
        if (j < 10000)
          dp_temp[j] += dp[j + 1];
        dp_temp[j] %= MOD;
      }
    }
    memcpy(dp, dp_temp, sizeof(dp));
    memset(dp_temp, 0, sizeof(dp));
  }
  cout << dp[0];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
