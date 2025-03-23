#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
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

bool comp(const pll& a, const pll& b) {
  if (a.SS == b.SS) return a.FF > b.FF;
  else return a.SS < b.SS;
}

void solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<pll> v(n);
  for (pll& i : v)
    cin >> i.FF >> i.SS;
  sort(all(v), comp);

  ll cost = v[0].SS, sum = cost, val = v[0].FF;
  ll ans = ( val >= m ) ? sum : LINF;
  for (int i = 1;i < n;i++) {
    val += v[i].FF;
    if (cost == v[i].SS) {
      sum += cost;
    }
    else {
      cost = v[i].SS;
      sum = cost;
    }

    if (val >= m)
      ans = min(ans, sum);
  }

  cout << ( ( ans == LINF ) ? -1 : ans );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
