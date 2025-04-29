//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, S;
  cin >> N >> S;
  vector<int> v(N);
  for (int& i : v)
    cin >> i;
  auto s = v.begin(), e = v.begin();
  int ans = INF;
  int sum = 0;
  while (e <= v.end()) {
    if (sum < S) {
      sum += *e;
      e++;
    }
    else {
      ans = min(ans, int(e - s));
      sum -= *s;
      s++;
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
