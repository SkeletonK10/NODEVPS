#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int mx = 0;
  for (int i = 0;i < n;i++) {
    int temp;
    cin >> temp;
    ans += __builtin_popcount(temp);
    mx = max(mx, temp);
  }
  while (mx > 1) {
    ans++;
    mx >>= 1;
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
