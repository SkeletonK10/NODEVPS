//////New Type Definition////////////////////////////////////////////////////////////////

#include <algorithm>
typedef std::pair<int, int> pii;

//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 1e9 + 7;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<pii> v(N);
  for (auto& [a, b] : v)
    cin >> a >> b;
  int ans = INF;
  for (int bm = 1;bm < ( 1 << N );bm++) {
    int sour = 1, bitter = 0;
    for (int i = 0;i < N;i++) {
      if (bm & ( 1 << i )) {
        sour *= v[i].first;
        bitter += v[i].second;
      }
    }
    ans = min(ans, abs(sour - bitter));
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
