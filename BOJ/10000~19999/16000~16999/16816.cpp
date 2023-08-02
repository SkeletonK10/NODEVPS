#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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

void solve() {
  ll s, t, d;
  cin >> s >> t >> d;
  ll goal = s - t;
  vector<ll> v(d);
  ll shortTerm = -INF, cycleTerm = 0;
  for (ll& i : v)
    cin >> i;

  for (int i = 0;i < d;i++) {
    cycleTerm -= v[i];
    shortTerm = max(shortTerm, cycleTerm);
    if (shortTerm >= goal) {
      cout << i + 1;
      return;
    }
  }

  if (cycleTerm <= 0) {
    cout << -1;
    return;
  }

  ll cycles = ( goal - shortTerm - 1 ) / cycleTerm + 1;
  ll curr = cycles * cycleTerm;
  for (int i = 0;i < d;i++) {
    curr -= v[i];
    if (curr >= goal) {
      cout << cycles * d + i + 1;
      return;
    }
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
