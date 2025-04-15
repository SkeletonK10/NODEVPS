#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int comb[31][31];

void preprocess() {
  comb[0][0] = 1;
  for (int i = 1;i <= 30;i++) {
    comb[i][0] = 1;
    for (int j = 1;j <= i;j++)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }
}

void solve() {
  preprocess();
  int r, c, w;
  cin >> r >> c >> w;
  r--; c--;
  ll ans = 0;
  for (int i = 0;i < w;i++)
    for (int j = 0;j <= i;j++)
      ans += comb[r + i][c + j];
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
