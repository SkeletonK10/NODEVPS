#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

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
  int q, mod;
  cin >> q >> mod;
  vector<int> v;
  vector<vector<int>> lastMod(mod);
  int sz = 0;

  while (q--) {
    int t, n;
    cin >> t;
    if (t == 1) {
      cin >> n;
      v.push_back(n % mod);
      lastMod[n % mod].push_back(sz);
      sz++;
    }
    else if (t == 2) {
      if (!v.empty()) {
        lastMod[v[sz - 1]].pop_back();
        v.pop_back();
        sz--;
      }
    }
    else {
      int ans = INF;
      for (int i = 0;i < mod;i++) {
        if (!lastMod[i].empty())
          ans = min(ans, lastMod[i].back());
        else {
          ans = INF;
          break;
        }
      }
      cout << ( ( ans == INF ) ? -1 : sz - ans ) << endl;
    }
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
