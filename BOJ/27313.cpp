#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> v(N);
  for (int& i : v)
    cin >> i;
  sort(v.begin(), v.end());

  int s = 0, e = N + 1;
  while (s < e) {
    int m = ( s + e ) / 2;
    ll t = 0;
    for (int i = 0;i < m;i++)
      if (( m - i - 1 ) % K == 0)
        t += v[i];
    if (t > M)
      e = m;
    else
      s = m + 1;
  }
  cout << s - 1;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
