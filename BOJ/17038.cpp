#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////Union-Find///////////////////////////////////////////

struct union_find {
  std::vector<int> arr;

  union_find(int sz) {
    arr.resize(sz + 1);
    for (int i = 1; i <= sz; i++)
      arr[i] = i;
  }

  int find(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = find(arr[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      arr[y] = x;
    }
  }
};

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  union_find uf(n);
  vector<tuple<string, int, int>> v(m);
  for (auto& [s, a, b] : v) {
    cin >> s >> a >> b;
    if (s[0] == 'S' && uf.find(a) != uf.find(b))
      uf.merge(a, b);
  }

  vector<vector<int>> adj(n + 1);
  vector<int> vst(n + 1);
  int cnt = 0;
  for (auto [s, a, b] : v) {
    if (s[0] == 'D') {
      a = uf.find(a);
      b = uf.find(b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  for (int i = 1;i <= n;i++) {
    int st = uf.find(i);
    if (!vst[st]) {
      cnt++;
      queue<int> q;
      q.push(st);
      vst[st] = 1;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
          if (!vst[next]) {
            vst[next] = ( vst[cur] == 1 ) ? 2 : 1;
            q.push(next);
          }
          else if (vst[cur] == vst[next]) {
            cout << 0;
            return;
          }
        }
      }
    }
  }

  cout << 1;
  while (cnt--)
    cout << 0;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
