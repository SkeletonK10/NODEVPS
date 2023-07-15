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

///////////////////////////////////////////////////////////

using namespace std;

bool comp(const pll& a, const pll& b) {
  if (a.SS == b.SS) return a.FF < b.FF;
  else return a.SS < b.SS;
}

void solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<pll> v(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> v[i].FF >> v[i].SS;
  sort(all(v), comp);

  map<ll, ll> prv, s;
  prv[0] = -1;
  for (int i = 1;i <= n;i++) {
    if (v[i - 1].SS != v[i].SS) {
      prv[v[i].SS] = v[i - 1].SS;
      s[v[i].SS] += s[v[i - 1].SS];
    }
    s[v[i].SS] += v[i].FF;
  }

  if (m > s[prv[v[n].SS]] && m <= s[v[n].SS]) {
    ll ls = 0, rem = m - s[prv[v[n].SS]];
    for (int i = n;v[i].SS == v[n].SS;i--) {
      ls += v[i].FF;
      if (ls >= rem) {
        cout << v[n].SS * ( n - i + 1 );
        return;
      }
    }
  }

  for (int i = 1;i <= n;i++) {
    if (m <= v[i].FF + s[prv[v[i].SS]]) {
      cout << v[i].SS;
      return;
    }
  }

  cout << -1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
