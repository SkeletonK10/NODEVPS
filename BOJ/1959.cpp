#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  ll n, m, x, y, ans = 0;
  cin >> n >> m;
  if (n <= m) {
    if (n % 2) {
      ans = n / 2 * 4;
      x = n / 2 + 1;
      y = m - ( n / 2 );
    }
    else {
      ans = n / 2 * 4 - 2;
      x = n / 2 + 1;
      y = n / 2;
    }
  }
  else {
    if (m % 2) {
      ans = m / 2 * 4 + 1;
      x = n - ( m / 2 );
      y = m / 2 + 1;
    }
    else {
      ans = m / 2 * 4 - 1;
      x = m / 2 + 1;
      y = m / 2;
    }
  }
  cout << ans << endl << x << ' ' << y;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
