#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

int furthest(vector<vector<int>>& adj, vector<int>& prev, vector<int>& dst, int start) {
  int mxDst = 0, ans = 0;
  stack<int> st;
  st.push(start);
  prev[start] = 0;
  dst[start] = 1;
  while (!st.empty()) {
    int cur = st.top();
    // cout << cur << dst[cur] << endl;
    st.pop();
    if (dst[cur] > mxDst) {
      mxDst = dst[cur];
      ans = cur;
    }
    for (int& nxt : adj[cur]) {
      if (prev[nxt] == -1) {
        st.push(nxt);
        prev[nxt] = cur;
        dst[nxt] = dst[cur] + 1;
      }
    }
  }
  // cout << endl;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < n - 1;i++) {
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }

  vector<int> prev(n + 1, -1), dst(n + 1);
  int d1 = furthest(adj, prev, dst, 1); // prev & dst: dummy
  fill(all(prev), -1);
  fill(all(dst), 0);
  int d2 = furthest(adj, prev, dst, d1);

  vector<int> route;
  for (int cur = d2; cur != d1; cur = prev[cur])
    route.push_back(cur);
  route.push_back(d1);

  // cout << "ROUTE SIZE: " << route.size() << endl;
  int ans = -1;
  vector<int> tempPrev(n + 1, -1), tempDst(n + 1);
  for (int i = 1;i < route.size() - 1;i++) {
    for (int& start : adj[route[i]]) {
      if (start == route[i - 1] || start == route[i + 1])
        continue;
      tempPrev[route[i]] = 0;
      int f = furthest(adj, tempPrev, tempDst, start);
      ans = max(ans, tempDst[f]);
    }
  }
  if (ans < 0) cout << 0;
  else cout << ans + dst[d2];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
