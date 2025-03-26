#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int dp[301][301];

void solve() {
  // fill(&dp[0][0], &dp[300][300] + 1, INF);
  int a, b;
  cin >> a >> b;
  string s1, s2;
  cin >> s1 >> s2;
  dp[0][0] = 0;
  for (int i = 1;i <= a;i++) {
    for (int j = 1;j <= b;j++) {
      int diff = abs((int)s1[i - 1] - (int)s2[j - 1]);
      // cout << diff << '|';
      dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + diff;
      // cout << dp[i][j] << ' ';
    }
    // cout << endl;
  }
  cout << dp[a][b];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
