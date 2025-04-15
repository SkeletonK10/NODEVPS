#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(30);
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    for (int b = 0;b < 30;b++)
      v[b] += ( temp & ( 1 << b ) ) ? 1 : 0;
  }
  ll ans = 1;
  for (int i = 1;i <= n;i++) {
    ll temp = 0;
    for (int b = 0;b < 30;b++)
      if (v[b] >= i)
        temp += 1 << b;
    ans = ( ans * temp ) % MOD;
  }
  cout << ( ans % MOD );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
