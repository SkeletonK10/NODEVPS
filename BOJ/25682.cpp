#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

char field[2001][2001];
int s[2001][2001];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1;i <= n;i++) {
    cin >> field[i - 1];
    for (int j = 1;j <= m;j++) {
      bool isW = field[i - 1][j - 1] == 'W';
      bool isOdd = ( i + j ) % 2;
      if (isOdd ^ isW) // i+j is Even && 'W', vice versa
        s[i][j]++;
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }
  int ans = k * k;
  for (int i = k;i <= n;i++) {
    for (int j = k;j <= m;j++) {
      int tAns = s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k];
      ans = min({ ans, tAns, k * k - tAns });
    }
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
