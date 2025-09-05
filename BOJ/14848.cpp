//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  int ans = N;
  vector<ll> v(K);
  for (ll& i : v)
    cin >> i;
  for (int bm = 1;bm < ( 1 << K );bm++) {
    ll l = 1;
    for (int i = 0;i < K;i++) {
      if (bm & ( 1 << i ))
        l = lcm(l, v[i]);
      if (l > N)
        break;
    }
    if (l > N)
      continue;

    ans -= ( N / l ) * ( __builtin_popcount(bm) & 1 ? 1 : -1 );
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
