#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  sort(all(v));
  v.push_back(INF);
  int d1 = v[0], d2 = v[1];
  for (int i = 0;i < n - 1;i++) {
    d1 = max(d1, v[i + 1] - v[i]);
    d2 = min(d2, v[i + 2] - v[i]);
  }
  if (d1 >= d2) cout << 0;
  else cout << d1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
