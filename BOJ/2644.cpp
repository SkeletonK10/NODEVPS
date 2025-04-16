#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, s, e, m;
  cin >> n >> s >> e >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < m;i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  vector<int> dst(n + 1, -1);
  q.push(s);
  dst[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dst[nxt] == -1) {
        dst[nxt] = dst[cur] + 1;
        q.push(nxt);
      }
    }
  }
  cout << dst[e];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
