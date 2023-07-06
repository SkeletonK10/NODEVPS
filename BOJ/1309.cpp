#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 9901;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int dp[100001][3];

void solve() {
  int n;
  cin >> n;
  dp[0][0] = 1;
  for (int i = 1;i <= n;i++) {
    dp[i][0] = ( dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] ) % MOD;
    dp[i][1] = ( dp[i - 1][0] + dp[i - 1][2] ) % MOD;
    dp[i][2] = ( dp[i - 1][0] + dp[i - 1][1] ) % MOD;
  }
  cout << ( dp[n][0] + dp[n][1] + dp[n][2] ) % MOD;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
