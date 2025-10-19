//////New Type Definition////////////////////////////////////////////////////////////////

#include <vector>
typedef std::tuple<int, int, int> tiii;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, C;
  cin >> N >> C;

  vector<int> idx(N);
  for (int i = 0;i < N;i++)
    idx[i] = i;
  vector<tiii> rules(C);
  for (int i = 0;i < C;i++) {
    int a;
    char x, y;
    cin >> a >> x >> y;
    rules[i] = { a, x - 'A', y - 'A' };
  }

  int ans = 0;
  do {
    for (auto [a, x, y] : rules) {
      if (a == 1) {
        if (idx[x] < idx[y])
          goto out;
      }
      if (a == 2) {
        if (idx[x] > idx[y])
          goto out;
      }
      if (a == 3) {
        if (abs(idx[x] - idx[y]) == 1)
          goto out;
      }
    }
    ans++;
  out:
  } while (next_permutation(idx.begin(), idx.end()));

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
