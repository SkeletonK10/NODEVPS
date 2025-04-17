#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  ll mn = 0, mx = 0;
  for (int i = 0;i < n;i++) {
    ll a, b;
    cin >> a >> b;
    mn += a; mx += b;
  }
  int ans = 0;
  for (int i = 63;i >= 0;i--) {
    ll bm = 1LL << i;
    ll mnB = mn & bm, mxB = mx & bm;
    if (mnB == mxB) {
      ans += !!mnB;
    }
    else {
      ans += i + 1;
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
