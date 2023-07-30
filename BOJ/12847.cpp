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
  int n, m;
  cin >> n >> m;
  vector<ll> v(n + 1);
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  ll a = 0;
  for (int i = 0;i <= n - m;i++)
    a = max(a, v[i + m] - v[i]);
  cout << a;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
