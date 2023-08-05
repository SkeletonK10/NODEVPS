#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ans = c / a;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  sort(all(v));
  int s = c;
  for (int i = n - 1;i >= 0;i--) {
    s += v[i];
    ans = max(ans, s / ( a + b * ( n - i ) ));
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
