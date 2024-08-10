#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int cnt[1000001];

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0;i < n;i++) {
    cin >> v[i];
    cnt[v[i]]++;
  }

  ll ans = 0;
  for (int i = 0;i < n;i++) {
    ll sq = v[i] * v[i];
    ll j = ( 2 * v[i] ) + 1;
    ll pl = j;
    while (pl <= 1000000) {
      ans += cnt[pl];
      j += 2;
      pl += j;
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
