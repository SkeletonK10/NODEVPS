#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
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

bool isIn(ll x, ll y, ll tx, ll ty, ll r) {
  return ( ( x - tx ) * ( x - tx ) + ( y - ty ) * ( y - ty ) <= ( r * r ) );
}

int ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) //a to b to c
{
  ll temp = ( bx - ax ) * ( cy - ay ) - ( by - ay ) * ( cx - ax );
  if (temp < 0) return -1;
  else if (temp > 0) return 1;
  else return 0;
}

void solve() {
  int n, k, r, q;
  cin >> n >> k >> r >> q;
  vector<pii> watch(SZ + 1);
  vector<int> dir(SZ + 1);
  int day, prv, x, y;
  cin >> day >> x >> y;
  watch[day] = { x,y };
  prv = day;
  for (int i = 0;i < k - 1;i++) {
    cin >> day >> x >> y;
    if (watch[prv].FF < x) {
      for (int i = 0;i <= day - prv;i++) {
        watch[prv + i] = { watch[prv].FF + i,y };
        dir[prv + i] = 1;
      }
    }
    if (watch[prv].FF > x) {
      for (int i = 0;i <= day - prv;i++) {
        watch[prv + i] = { watch[prv].FF - i,y };
        dir[prv + i] = -1;
      }
    }
    if (watch[prv].SS < y) {
      for (int i = 0;i <= day - prv;i++) {
        watch[prv + i] = { x,watch[prv].SS + i };
        dir[prv + i] = 2;
      }
    }
    if (watch[prv].SS > y) {
      for (int i = 0;i <= day - prv;i++) {
        watch[prv + i] = { x,watch[prv].SS - i };
        dir[prv + i] = -2;
      }
    }
    prv = day;
  }

  while (q--) {
    cin >> day >> x >> y;
    auto [tx, ty] = watch[day];
    if (!isIn(x, y, tx, ty, r)) {
      cout << "gori" << endl;
      continue;
    }

    ll p1x, p1y, p2x, p2y;
    if (dir[day] == 1) {
      p1x = tx - 1;
      p1y = ty;
      p2x = tx + 1;
      p2y = ty;
    }
    if (dir[day] == -1) {
      p1x = tx + 1;
      p1y = ty;
      p2x = tx - 1;
      p2y = ty;
    }
    if (dir[day] == 2) {
      p1x = tx;
      p1y = ty - 1;
      p2x = tx;
      p2y = ty + 1;
    }
    if (dir[day] == -2) {
      p1x = tx;
      p1y = ty + 1;
      p2x = tx;
      p2y = ty - 1;
    }

    int res = ccw(p1x, p1y, p2x, p2y, x, y);
    if (res == 1)
      cout << "safe" << endl;
    if (res == -1)
      cout << "unsafe" << endl;
    if (res == 0)
      cout << "gori" << endl;
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
