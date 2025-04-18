#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> vst;
int cnt; // 0

void dfs(int cur) {
  vst[cur] = ++cnt;
  for (int nxt : adj[cur])
    if (vst[nxt] == 0)
      dfs(nxt);
}

void solve() {
  int N, M, R;
  cin >> N >> M >> R;
  adj.resize(N + 1);
  vst.resize(N + 1);
  for (int i = 0;i < M;i++) {
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  for (int i = 1;i <= N;i++)
    sort(adj[i].rbegin(), adj[i].rend());
  dfs(R);
  for (int i = 1;i <= N;i++)
    cout << vst[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
