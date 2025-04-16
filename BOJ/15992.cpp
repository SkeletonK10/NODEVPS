#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 9;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll dp[1001][1001];  // dp[i][j]: i개의 수를 써서 j 만들기

void preprocess() {
  dp[0][0] = 1;
  for (int i = 1;i <= 1000;i++) {
    for (int j = 1;j <= 1000;j++) {
      if (j >= 1)
        dp[i][j] += dp[i - 1][j - 1];
      if (j >= 2)
        dp[i][j] += dp[i - 1][j - 2];
      if (j >= 3)
        dp[i][j] += dp[i - 1][j - 3];
      dp[i][j] %= MOD;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  cout << dp[m][n] << endl;
}

int main() {
  FastIO;
  preprocess();
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
