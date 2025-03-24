#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[3] = 0;
  dp[4] = 1;
  dp[5] = 2;
  for (int i = 6;i <= n;i++)
    dp[i] = 2 + dp[( i + 1 ) / 2];
  cout << dp[n];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
