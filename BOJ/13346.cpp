#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int q, n, d;
  cin >> q >> n >> d;
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<ll>> v(n + 1, vector<ll>(3)), dp(n + 1, vector<ll>(d + 1));
  for (int i = 1;i <= n;i++) {
    int loc = i - 1;
    if (s1[loc] == s2[loc]) {
      v[i][0] = 1;
      v[i][1] = 0;
      v[i][2] = q - 1;
    }
    else {
      v[i][0] = 0;
      v[i][1] = 2;
      v[i][2] = q - 2;
    }
  }

  dp[0][0] = 1;

  for (int i = 1; i <= n;i++) {
    for (int j = 0; j <= d;j++) {
      dp[i][j] += dp[i - 1][j] * v[i][0];
      if (j >= 1)
        dp[i][j] += dp[i - 1][j - 1] * v[i][1];
      if (j >= 2)
        dp[i][j] += dp[i - 1][j - 2] * v[i][2];
    }
  }
  cout << dp[n][d];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
