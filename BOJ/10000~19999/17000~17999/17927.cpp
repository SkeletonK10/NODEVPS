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

ll permu(int n, int r) {
  ll res = 1;
  for (int i = n;i > ( n - r );i--)
    res = ( res * i ) % MOD;
  return res;
}

void solve() {
  int n, g;
  cin >> n >> g;
  vector<int> v(g + 1);
  int prev = 0;
  for (int i = 1; i <= g;i++) {
    cin >> v[i];
    if (prev >= v[i]) {
      cout << 0;
      return;
    }
    prev = v[i];
  }
  if (prev != n) {
    cout << 0;
    return;
  }

  ll ans = 1;
  for (int i = 0;i < g;i++)
    ans = ( ans * permu(n - v[i] - 1, v[i + 1] - v[i] - 1) ) % MOD;
  cout << ans % MOD;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
