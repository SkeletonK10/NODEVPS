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
  cin >> s >> t;
  int i = 0, ans = 1;
  for (char c : t) {
    while (true) {
      if (i == 26) {
        i = 0;
        ans++;
      }
      char d = s[i];
      i++;
      if (c == d)
        break;
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
