#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  vector<int> low(n + 1);
  for (int i = 1;i <= n;i++) {
    int temp;
    cin >> temp;
    x += temp;
    if (x < k)
      low[i]++;
    low[i] += low[i - 1];
  }
  while (m--) {
    int s, e;
    cin >> s >> e;
    e--; s--;
    cout << low[e] - low[s] << endl;
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
