//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(7));
  for (int i = 0;i < N;i++)
    for (int j = 0;j < 5;j++)
      cin >> v[i][j];

  int checked = 0;
  int idx = -1;
  int ans = 0;
  while (checked < N) {
    idx++;
    ans++;
    if (idx == 7) idx = 0;
    if (v[checked][idx]) {
      checked++;
      continue;
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
