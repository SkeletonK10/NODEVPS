#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int x, y, per;
  cin >> x >> y;
  per = ( x + y ) * 2;
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0;i <= n;i++) {
    int a, b, temp;
    cin >> a >> b;
    if (a == 1)
      temp = x + y + b;
    else if (a == 2)
      temp = x - b;
    else if (a == 3)
      temp = x + y - b;
    else
      temp = x + y + x + b;
    v.push_back(temp);
  }
  int ans = 0;
  for (int i = 0;i < n;i++) {
    int dist = abs(v[n] - v[i]);
    ans += min(dist, per - dist);
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
