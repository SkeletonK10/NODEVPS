#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

bool compSS(const pll& a, const pll& b) {
  return a.SS < b.SS;
}

void solve() {
  int n, t;
  cin >> n >> t;
  vector<pll> v(n);
  for (auto& [a, b] : v)
    cin >> a >> b;
  sort(all(v), compSS);

  ll ans = 0;
  for (int i = t - n;i < t;i++) {
    int index = i - ( t - n );
    ans += v[index].FF + v[index].SS * i;
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
