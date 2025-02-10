#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int MOD = 1e9 + 9;

char field[3001][3001];
int ans[3001][3001];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0;i < n;i++)
    cin >> field[i];
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      ans[i][j] += 1;
      ans[i][j] %= MOD;
      if (field[i][j] == 'E')
        ans[i][j + 1] += ans[i][j];
      if (field[i][j] == 'S')
        ans[i + 1][j] += ans[i][j];
      if (field[i][j] == 'B') {
        ans[i][j + 1] += ans[i][j];
        ans[i + 1][j] += ans[i][j];
      }
    }
  }
  cout << ans[n - 1][m - 1];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
