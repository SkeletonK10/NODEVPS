#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int k, h, q;
  cin >> k >> h >> q;
  vector<ll> keys(h + 1);
  keys[0] = 1;
  for (int i = 1;i <= h;i++)
    keys[i] = keys[i - 1] * ( k + 1 );

  while (q--) {
    ll a, b;
    cin >> a >> b;
    if (a > keys[h] - 1 || b > keys[h] - 1) {
      cout << -1 << endl;
      continue;
    }
    if (a == b) {
      cout << 0 << endl;
      continue;
    }

    int rh = h - 1;
    while (true) {
      if (a / keys[rh] == b / keys[rh] && a % keys[rh] && b % keys[rh]) {
        a %= keys[rh];
        b %= keys[rh];
        rh--;
      }
      else break;
    }

    int ans = 0;
    int ah = rh, bh = rh;
    while (ah >= 0) {
      ans++;
      if (a % keys[ah] == 0)
        break;
      a %= keys[ah];
      ah--;
    }
    while (bh >= 0) {
      ans++;
      if (b % keys[bh] == 0)
        break;
      b %= keys[bh];
      bh--;
    }
    cout << ans << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
