#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    adj[e].push_back(s);
  }

  vector<int> ans;
  int ansCnt = 0;
  for (int i = 1;i <= n;i++) {
    vector<bool> vst(n + 1);
    queue<int> q;
    int in = 1;
    q.push(i);
    vst[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int& next : adj[cur]) {
        if (!vst[next]) {
          in++;
          q.push(next);
          vst[next] = true;
        }
      }
    }
    if (ansCnt < in) {
      ansCnt = in;
      ans = { i };
    }
    else if (ansCnt == in)
      ans.push_back(i);
  }
  for (int& i : ans)
    cout << i << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
