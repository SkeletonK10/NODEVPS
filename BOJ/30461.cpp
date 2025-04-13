#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> ps(n + 1, vector<int>(m + 1));
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      cin >> ps[i][j];
      ps[i][j] += ps[i - 1][j - 1] + ps[i - 1][j];
      if (i > 1)
        ps[i][j] -= ps[i - 2][j - 1];
    }
  }
  while (q--) {
    int w, p;
    cin >> w >> p;
    cout << ps[w][p] << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
