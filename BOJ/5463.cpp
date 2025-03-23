#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 1987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int dp[51][51][51][51];
int field[51][51], sum[51][51];

int s(int sx, int sy, int rx, int ry) {
  sx--; sy--;
  return sum[sx + rx][sy + ry] - sum[sx][sy + ry] - sum[sx + rx][sy] + sum[sx][sy];
}

int f(int sx, int sy, int rx, int ry) {
  if (dp[sx][sy][rx][ry])
    return dp[sx][sy][rx][ry];
  if (rx == 1 && ry == 1)
    return 0;
  int res = INF;
  for (int i = 1;i < rx;i++)
    res = min(res, f(sx, sy, i, ry) + f(sx + i, sy, rx - i, ry));
  for (int i = 1;i < ry;i++)
    res = min(res, f(sx, sy, rx, i) + f(sx, sy + i, rx, ry - i));
  return dp[sx][sy][rx][ry] = res + s(sx, sy, rx, ry);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      cin >> field[i][j];
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + field[i][j];
    }
  }
  cout << f(1, 1, n, m);
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
