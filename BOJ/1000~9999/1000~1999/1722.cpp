#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll fact(int n) {
  ll res = 1;
  for (int i = 2;i <= n;i++)
    res *= i;
  return res;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<bool> used(n + 1);
  if (q == 1) {
    ll a;
    cin >> a;
    a--;
    for (int i = n - 1;i >= 0;i--) {
      int qt = ( a % fact(i + 1) ) / fact(i);
      int cnt = 0;
      for (int j = 1;j <= n;j++) {
        if (!used[j])
          cnt++;
        if (cnt > qt) {
          used[j] = true;
          cout << j << ' ';
          break;
        }
      }
    }
  }
  else if (q == 2) {
    ll ans = 0;
    for (int i = n - 1;i >= 0;i--) {
      int inp, cnt = 0;
      cin >> inp;
      for (int j = 1;j < inp;j++)
        if (!used[j])
          cnt++;
      used[inp] = true;
      ans += fact(i) * cnt;
    }
    cout << ans + 1;
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
