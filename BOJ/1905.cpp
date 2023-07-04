#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

bool overlap(pair<pii, pii>& a, pair<pii, pii>& b) {
  bool xo = false, yo = false;
  if (a.FF.FF == b.FF.FF)
    xo = true;
  if (a.FF.FF < b.FF.FF && a.SS.FF > b.FF.FF)
    xo = true;
  if (b.FF.FF < a.FF.FF && b.SS.FF > a.FF.FF)
    xo = true;

  if (a.FF.SS == b.FF.SS)
    yo = true;
  if (a.FF.SS < b.FF.SS && a.SS.SS > b.FF.SS)
    yo = true;
  if (b.FF.SS < a.FF.SS && b.SS.SS > a.FF.SS)
    yo = true;
  return xo && yo;
}

void solve() {
  int a, b, n;
  cin >> a >> b >> n;
  vector<pair<pii, pii>> v(n + 1);
  vector<vector<int>> adj(n + 1);
  vector<int> c(n + 1), dgr(n + 1), dp(n + 1);
  for (int i = 1;i <= n;i++) {
    int lx, ly, lz, px, py;
    cin >> lx >> ly >> lz >> px >> py;
    v[i] = { {px, py}, {px + lx, py + ly} };
    c[i] = lz;
  }
  int ans = 0;
  for (int i = 1;i <= n;i++) {
    dp[i] = c[i];
    for (int j = 1;j < i;j++)
      if (overlap(v[i], v[j]))
        dp[i] = max(dp[i], dp[j] + c[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
