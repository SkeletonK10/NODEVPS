#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll square(ll x) {
  return x * x;
}

// x = x1 + ( x2 - x1 ) * t
// y = y1 + ( y2 - y1 ) * t
// where 0 <= t <= 1

void solve() {
  ll x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ll sq = square(x2 + x3 - x1 - x4) + square(y2 + y3 - y1 - y4);
  ll l = ( ( x1 - x3 ) * ( x2 + x3 - x1 - x4 ) + ( y1 - y3 ) * ( y2 + y3 - y1 - y4 ) ) << 1;
  double t;
  if (!sq || !l)
    t = 0;
  else
    t = clamp((double)l / ( sq * ( -2 ) ), 0.0, 1.0);
  cout << fixed << setprecision(10);
  cout << sqrt(pow(x1 - x3 + ( x2 + x3 - x1 - x4 ) * t, 2) + pow(y1 - y3 + ( y2 + y3 - y1 - y4 ) * t, 2));
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
