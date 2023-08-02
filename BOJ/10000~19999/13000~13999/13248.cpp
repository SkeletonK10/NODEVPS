#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

double solve() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int cycle = a + b;
  int deno = e - d;
  if (!deno) {
    if (( d % cycle ) <= a || ( 0 < ( ( d + c ) % cycle ) && ( ( d + c ) % cycle ) <= a ))
      return 0.0;
    else return 1.0;
  }

  if (c >= b) return 0.0;

  int sf = a, ef = a + b - c;
  int nmr = 0;
  if (d % cycle) {
    nmr += ( d % cycle ) < ef ? ef - max(sf, d % cycle) : 0;
    d += cycle - ( d % cycle );
  }
  if (e % cycle) {
    nmr += ( e % cycle ) > sf ? min(e % cycle, ef) - sf : 0;
    e -= e % cycle;
  }
  nmr += ( ef - sf ) * ( ( e - d ) / cycle );

  return (double)nmr / deno;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    cout << fixed << setprecision(10) << solve();
  }
}
