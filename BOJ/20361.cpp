#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, x, k;
  cin >> n >> x >> k;
  vector<int> v(n + 1);
  v[x] = 1;
  while (k--) {
    int s, e;
    cin >> s >> e;
    swap(v[s], v[e]);
  }
  for (int i = 1;i <= n;i++)
    if (v[i] == 1)
      cout << i;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
