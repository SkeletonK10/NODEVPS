//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<string> v(n);
  for (string& s : v)
    cin >> s;

  sort(v.begin(), v.end());

  vector<int> need(n);
  for (int i = 0;i < n - 1;i++) {
    for (int j = 0;j < l;j++) {
      if (v[i][j] == v[i + 1][j]) {
        need[i] = max(need[i], j + 1);
        need[i + 1] = max(need[i + 1], j + 1);
      }
      else break;
    }
  }
  int ans = 0;
  for (int i : need)
    ans += i;
  cout << ans + n;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
