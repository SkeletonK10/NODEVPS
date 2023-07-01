#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////Union-Find///////////////////////////////////////////

struct union_find {
  std::vector<int> arr, clean, cnt;

  union_find(int sz, std::vector<int>& c) {
    arr.resize(sz + 1);
    for (int i = 1; i <= sz; i++)
      arr[i] = i;
    clean = { all(c) };
    cnt = std::vector<int>(sz + 1, 1);
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
      clean[x] += clean[y];
      cnt[x] += cnt[y];
    }
  }

  bool query(int x) {
    x = find(x);
    return ( clean[x] * 2 ) > cnt[x];
  }
};

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> c(n + 1);
  for (int i = 1;i <= n;i++)
    cin >> c[i];

  union_find uf(n, c);
  while (m--) {
    int s, e;
    cin >> s >> e;
    uf.merge(s, e);
  }
  while (q--) {
    int x;
    cin >> x;
    cout << ( uf.query(x) ? 1 : 0 ) << endl;
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
