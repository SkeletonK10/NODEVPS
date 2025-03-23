#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int dp[27][2];

void solve() {
  string s;
  cin >> s;
  vector<int> f(27, -1), l(27, -1), cnt(27);
  for (int i = 0;i < s.size();i++) {
    int idx = s[i] - 'a' + 1;
    if (f[idx] == -1) f[idx] = i;
    l[idx] = i;
    cnt[idx]++;
  }
  f[0] = l[0] = 0;
  int last = 0;
  for (int i = 1;i <= 26;i++) {
    if (!cnt[i]) {
      dp[i][0] = dp[last][0];
      dp[i][1] = dp[last][1];
    }
    else {
      dp[i][0] = min(
        dp[last][0] + abs(f[last] - l[i]),
        dp[last][1] + abs(l[last] - l[i])) + ( l[i] - f[i] ) + cnt[i];
      dp[i][1] = min(
        dp[last][0] + abs(f[last] - f[i]),
        dp[last][1] + abs(l[last] - f[i])) + ( l[i] - f[i] ) + cnt[i];
      last = i;
    }
  }
  cout << min(dp[26][0], dp[26][1]);
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
