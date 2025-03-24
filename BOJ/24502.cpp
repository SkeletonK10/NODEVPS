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
  ll n, k;
  ll ans = 0;
  cin >> n >> k;
  vector<ll> v(n + 1);
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    v[i] %= k;
  }
  ll rem = 0;
  int i = 1;
  while (i <= n) {
    while (i <= n) {
      // cout << i << ' ' << rem << endl;
      rem += v[i];
      v[i] = 0;
      if (rem * 2 > k)
        break;
      ans += rem;
      i++;
    }
    while (i <= n) {
      // cout << rem << endl;
      rem += v[i];
      v[i] = 0;
      if (rem >= k) {
        rem -= k;
        break;
      }
      ans += k - rem;
      i++;
    }
  }
  // cout << rem << endl;
  if (rem) {
    cout << "blobsad";
    return;
  }
  else {
    cout << ans;
    return;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
