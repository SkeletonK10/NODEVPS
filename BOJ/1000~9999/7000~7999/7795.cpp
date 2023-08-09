#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n), u(m);
  for (int& i : v)
    cin >> i;
  for (int& j : u)
    cin >> j;
  sort(all(u));
  int ans = 0;
  for (int& i : v)
    ans += lower_bound(all(u), i) - u.begin();
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
