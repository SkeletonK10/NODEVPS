#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll solve() {
  ll ans = 1;
  for (int i = 1;i <= 42;i++) {
    ll reply;
    cout << "? " << ans << endl;
    cin >> reply;
    if (reply < ans)
      return ans - reply;
    else
      ans *= 2;
  }
  return -1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    ll ans = solve();
    cout << "! " << ans << endl;
  }
}
