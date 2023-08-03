#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, prv = 1;
  vector<int> ap(100001);
  ll ans = 0;

  cin >> n;
  for (int i = 1;i <= n;i++) {
    int a;
    cin >> a;
    prv = min(prv + 1, i - ap[a]);
    ans += prv;
    ap[a] = i;
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
