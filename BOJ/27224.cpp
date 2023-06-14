#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

bool check(int target, int k, int m, vector<int>& v) {
  int cnt = 0;
  for (int i = 0;i < k;i++)
    if (v[i] <= target)
      cnt++;
  if (cnt < m) return false;
  for (int i = k;i < v.size();i++) {
    if (v[i] <= target)
      cnt++;
    if (v[i - k] <= target)
      cnt--;
    if (cnt < m) return false;
  }
  return true;
}

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  int l = 0, r = 1e9 + 7;
  int a = 0;
  while (l < r) {
    int mid = ( l + r ) / 2;
    if (check(mid, k, m, v))
      r = mid;
    else
      l = mid + 1;
  }

  ll ans = -l;
  for (int& i : v) {
    if (i > l) ans += i;
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
