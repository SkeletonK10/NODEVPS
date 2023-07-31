#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  ll n, m, s = 0, ans = 0;
  map<ll, int> mp;
  cin >> n >> m;
  for (int i = 1;i <= n;i++) {
    ll temp, d;
    cin >> temp;
    s += temp;
    d = s - m * i;
    ans += mp[d];
    mp[d]++;
    if (!d)
      ans++;
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
