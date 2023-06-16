#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

int solve() {
  int w, h, a;
  cin >> w >> h >> a;

  vector<pii> factor;
  for (int i = 1;i * i <= a;i++)
    if (a % i == 0)
      factor.push_back({ i,a / i });

  int sz = factor.size();
  for (int i = 0;i < sz;i++)
    factor.push_back({ factor[i].SS, factor[i].FF });

  int ans = INF;
  for (auto& [x, y] : factor) {
    if (w < x || h < y) continue;
    int tw = w, th = h;
    int tans = 0;
    while (tw > x) {
      tans++;
      tw = ( tw + 1 ) / 2;
    }
    while (th > y) {
      tans++;
      th = ( th + 1 ) / 2;
    }
    ans = min(ans, tans);
  }
  return ( ans == INF ) ? -1 : ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    cout << solve();
  }
}
