#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1);
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    adj[e].push_back(s);
    deg[s]++;
  }
  queue<int> q;
  for (int i = 1;i <= n;i++) {
    if (!deg[i]) {
      q.push(i);
    }
  }
  int ans = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    ans++;
    for (int& nxt : adj[cur]) {
      deg[nxt]--;
      if (!deg[nxt])
        q.push(nxt);
    }
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
