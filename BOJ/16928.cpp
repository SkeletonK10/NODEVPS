#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> adj(101, -1);
  for (int i = 0;i < n + m;i++) {
    int s, e;
    cin >> s >> e;
    adj[s] = e;
  }
  queue<int> q;
  vector<int> vst(101, -1);
  q.push(1);
  vst[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 1;i <= 6;i++) {
      int nxt = cur + i;
      if (nxt > 100)
        break;
      if (adj[nxt] != -1)
        nxt = adj[nxt];
      if (vst[nxt] == -1) {
        vst[nxt] = vst[cur] + 1;
        q.push(nxt);
      }
    }
  }
  cout << vst[100];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
