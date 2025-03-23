#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  ll n;
  cin >> n;
  ll l = 1, r = 1e9;
  while (l < r) {
    ll m = ( l + r ) / 2;
    if (m * ( m + 1 ) / 2 > n)
      r = m;
    else
      l = m + 1;
  }
  cout << l - 1 << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
