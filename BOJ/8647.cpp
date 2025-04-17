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
  int n, m;
  cin >> n >> m;
  vector<ll> v1(n + 1), v2(m + 1);
  for (int i = 1;i <= n;i++)
    cin >> v1[i];
  for (int i = 1;i <= m;i++)
    cin >> v2[i];
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  if (v1.back() != v2.back()) {
    cout << "NIE";
    return;
  }

  vector<ll> s(m + 1);
  for (int i = 1;i <= m;i++)
    s[i] = s[i - 1] + v2[i];

  ll ans = 0;
  for (ll& a : v1) {
    int lb = lower_bound(v2.begin(), v2.end(), a) - v2.begin();
    ans += s[lb] - ( v2[lb] - a );
    ans += a * ( m - lb );
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
