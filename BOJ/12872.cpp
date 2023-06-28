#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const int MOD = 1e9 + 7;

using namespace std;

ll comb[101][101];

ll cases(int n, int m, int p) {
  ll res = 1;
  if (n <= m && n < p) {
    return 0;
  }
  for (int i = 0;i < m;i++)
    res = ( res * ( n - i ) ) % MOD;
  for (int i = 0;i < p - m;i++)
    res = ( res * ( n - m ) ) % MOD;
  return res;
}

void solve() {
  comb[0][0] = 1;
  for (int i = 1;i <= 100;i++) {
    for (int j = 0;j <= i;j++) {
      if (j != 0)
        comb[i][j] += comb[i - 1][j - 1];
      if (j != i)
        comb[i][j] += comb[i - 1][j];
      comb[i][j] %= MOD;
    }
  }

  int n, m, p;
  cin >> n >> m >> p;

  ll ans = 0;
  for (int i = 0;i <= n;i++) {
    if (i % 2)
      ans = ( ans + ( comb[n][i] * ( MOD - cases(n - i, m, p) ) ) ) % MOD;
    else
      ans = ( ans + ( comb[n][i] * cases(n - i, m, p) ) ) % MOD;
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
