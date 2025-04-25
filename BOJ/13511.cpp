#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
int depth[100001];
int parent[100001][18];
ll cost[100001][18];

void getParent(int cur, int prev, vector<vector<pii>>& adj, int d = 0) {
  for (auto [nxt, c] : adj[cur]) {
    if (nxt != prev) {
      depth[nxt] = d + 1;
      parent[nxt][0] = cur;
      cost[nxt][0] = c;
      getParent(nxt, cur, adj, d + 1);
    }
  }
}

void initTable() {
  for (int i = 1;i < 18;i++) {
    for (int v = 1;v <= N;v++) {
      parent[v][i] = parent[parent[v][i - 1]][i - 1];
      cost[v][i] = cost[v][i - 1] + cost[parent[v][i - 1]][i - 1];
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int dDiff = depth[a] - depth[b];
  for (int i = 17;i >= 0;i--)
    if (dDiff & ( 1 << i ))
      a = parent[a][i];
  if (a == b) return a;
  for (int i = 17;i >= 0;i--) {
    if (parent[a][i] != parent[b][i]) {
      a = parent[a][i];
      b = parent[b][i];
    }
  }
  return parent[a][0];
}

ll lcaCost(int a, int b) {
  ll res = 0;
  if (depth[a] < depth[b]) swap(a, b);
  int dDiff = depth[a] - depth[b];
  for (int i = 17;i >= 0;i--) {
    if (dDiff & ( 1 << i )) {
      res += cost[a][i];
      a = parent[a][i];
    }
  }
  if (a == b) return res;
  for (int i = 17;i >= 0;i--) {
    if (parent[a][i] != parent[b][i]) {
      res += cost[a][i] + cost[b][i];
      a = parent[a][i];
      b = parent[b][i];
    }
  }
  return res + cost[a][0] + cost[b][0];
}

int nthParent(int a, int dDiff) {
  for (int i = 17;i >= 0;i--)
    if (dDiff & ( 1 << i ))
      a = parent[a][i];
  return a;
}

void solve() {
  cin >> N;
  vector<vector<pii>> adj(N + 1);
  for (int i = 0;i < N - 1;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    adj[e].push_back({ s,c });
  }
  getParent(1, 0, adj);
  initTable();

  int Q;
  cin >> Q;
  while (Q--) {
    int cmd, u, v, k;
    cin >> cmd >> u >> v;
    if (cmd == 1) {
      cout << lcaCost(u, v) << endl;
    }
    else {
      cin >> k;
      k--;
      int l = lca(u, v);
      if (k <= depth[u] - depth[l]) {

        cout << nthParent(u, k) << endl;
      }
      else {
        k -= depth[u] - depth[l];
        cout << nthParent(v, depth[v] - depth[l] - k) << endl;
      }
    }
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
