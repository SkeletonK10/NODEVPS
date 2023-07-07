#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int dfs_h(int parent, int cur, vector<vector<int>>& adj, vector<int>& h) {
  int res = 0;
  for (int& next : adj[cur]) {
    if (next == parent)
      continue;
    res = max(res, dfs_h(cur, next, adj, h));
  }
  return h[cur] = ++res;
}

int dfs_d(int parent, int cur, int d, vector<vector<int>>& adj, vector<int>& h) {
  int res = 0;
  for (int& next : adj[cur]) {
    if (next == parent)
      continue;
    if (h[next] > d)
      res += dfs_d(cur, next, d, adj, h) + 2;
  }
  return res;
}

void solve() {
  int n, s, d;
  cin >> n >> s >> d;
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < n - 1;i++) {
    int l, r;
    cin >> l >> r;
    adj[l].push_back(r);
    adj[r].push_back(l);
  }

  vector<int> h(n + 1);
  dfs_h(0, s, adj, h);
  cout << dfs_d(0, s, d, adj, h);
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
