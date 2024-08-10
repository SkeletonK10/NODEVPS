#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  ll res = ( x2 - x1 ) * ( y3 - y1 ) - ( x3 - x1 ) * ( y2 - y1 );
  if (res > 0) return 1;
  if (res < 0) return -1;
  return 0;
}

int solve() {
  int x1, y1, x2, y2, x3, y3;
  int ans = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (!ccw(x1, y1, x2, y2, x3, y3)) return 0;
  for (int i = 0;i <= 100;i++) {
    for (int j = 0;j <= 100;j++) {
      int c12 = ccw(i, j, x1, y1, x2, y2);
      int c23 = ccw(i, j, x2, y2, x3, y3);
      int c31 = ccw(i, j, x3, y3, x1, y1);
      if (c12 == c23 && c23 == c31)
        ans++;
    }
  }
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    cout << solve() << endl;
  }
}
