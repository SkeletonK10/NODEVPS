#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int s, e, n;
  cin >> s >> e >> n;
  int ans = abs(s - e);
  for (int i = 0;i < n;i++) {
    int d;
    cin >> d;
    ans = min(ans, abs(d - e) + 1);
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
