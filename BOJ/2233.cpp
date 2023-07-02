#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
  int n, x, y;
  string s;
  cin >> n >> s >> x >> y;
  vector<int> parent(n + 1), in(n + 1), out(n + 1), depth(n + 1);
  stack<int> st;
  st.push(0);

  int cnt = 0;
  for (int i = 0;i < s.length();i++) {
    if (s[i] == '0') {
      cnt++;
      depth[cnt] = st.size();
      parent[cnt] = st.top();
      st.push(cnt);
      in[cnt] = i + 1;
    }
    else {
      out[st.top()] = i + 1;
      st.pop();
    }
  }

  for (int i = 1;i <= n;i++) {
    if (x == in[i])
      x = i;
    if (x == out[i])
      x = i;
    if (y == in[i])
      y = i;
    if (y == out[i])
      y = i;
  }

  if (depth[x] > depth[y])
    swap(x, y);
  while (depth[x] < depth[y])
    y = parent[y];
  while (x != y) {
    x = parent[x];
    y = parent[y];
  }
  cout << in[x] << ' ' << out[x];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
