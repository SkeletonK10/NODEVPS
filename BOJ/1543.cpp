//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  s = '.' + s;
  int ls = s.length(), lt = t.length();
  vector<int> dp(ls);
  int ans = 0;
  for (int i = 1;i <= ls - lt;i++) {
    bool judge = true;
    for (int j = 0;j < lt;j++) {
      if (s[i + j] != t[j]) {
        judge = false;
        break;
      }
    }

    int& ret = dp[i + lt - 1];
    if (judge)
      ret++;
    ret += dp[i - 1];
    ret = max(ret, dp[i + lt - 2]);

    ans = max(ans, ret);
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
