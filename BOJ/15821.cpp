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
  int n, k;
  cin >> n >> k;
  vector<ll> v;
  for (int i = 0;i < n;i++) {
    int vtx;
    cin >> vtx;
    ll mx = 0;
    for (int j = 0;j < vtx;j++) {
      ll x, y;
      cin >> x >> y;
      mx = max(mx, x * x + y * y);
    }
    v.push_back(mx);
  }
  sort(v.begin(), v.end());
  cout << v[k - 1] << ".00";
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
