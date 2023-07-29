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
  int n;
  cin >> n;
  vector<int> v(n + 1);
  vector<pii> ans;
  int mx = -INF, mn = INF;
  int mxi, mni;
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    if (mx < v[i]) {
      mx = v[i];
      mxi = i;
    }
    if (mn > v[i]) {
      mn = v[i];
      mni = i;
    }
  }
  if (mx == 0 && mn == 0) {
    cout << 0 << endl;
    return;
  }
  if (mx > 0) {
    while (mx < 40) {
      ans.push_back({ mxi,mxi });
      mx += mx;
    }
    if (mxi != 1) {
      ans.push_back({ 1,mxi });
      ans.push_back({ 1,mxi });
    }
    for (int i = 1;i <= n - 1;i++) {
      ans.push_back({ i + 1,i });
      ans.push_back({ i + 1,i });
    }
  }
  else {
    while (mn > -40) {
      ans.push_back({ mni,mni });
      mn += mn;
    }
    if (mni != n) {
      ans.push_back({ n,mni });
      ans.push_back({ n,mni });
    }
    for (int i = n;i > 1;i--) {
      ans.push_back({ i - 1,i });
      ans.push_back({ i - 1,i });
    }
  }
  cout << ans.size() << endl;
  for (auto& [a, b] : ans)
    cout << a << ' ' << b << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
