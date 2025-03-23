#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<tiii> v(n);
  for (auto& [x, y, z] : v)
    cin >> x >> y >> z;

  int ans = INF;
  for (int i = 0;i < n;i++) {
    int m1 = INF, m2 = INF;
    auto [x1, y1, z1] = v[i];
    for (int j = 0;j < n;j++) {
      if (i == j) continue;
      auto [x2, y2, z2] = v[j];
      int d = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
      m2 = min(m2, d);
      if (m2 < m1) swap(m1, m2);
    }
    ans = min(ans, m1 + m2);
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
