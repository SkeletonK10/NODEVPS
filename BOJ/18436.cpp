#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

template <typename T>
struct segTree {
private:
  int sz, treeSZ;
  std::vector<T> tree;
  T _init(std::vector<T>& v, int node = 0, int s = 0, int e = -1) {
    if (e == -1) e = treeSZ / 2 - 1;
    if (s == e)
      return tree[node] = ( sz <= s ? 0 : ( v[s] % 2 ? 1 : 0 ) );
    int m = ( s + e ) >> 1;
    return tree[node] = _init(v, node * 2 + 1, s, m) + _init(v, node * 2 + 2, m + 1, e);
  }

public:
  segTree(std::vector<T>& v) {
    sz = v.size();
    treeSZ = 1;
    while (treeSZ < sz)
      treeSZ <<= 1;
    treeSZ <<= 1;
    tree.resize(treeSZ);

    _init(v);
  }

  T query(int l, int r, int node = 0, int s = 0, int e = -1) {
    if (e == -1) e = treeSZ / 2 - 1;
    if (l <= s && e <= r) {
      return tree[node];
    }
    else if (e < l || r < s) {
      return 0;
    }
    else {
      int m = ( s + e ) >> 1;
      return query(l, r, node * 2 + 1, s, m) + query(l, r, node * 2 + 2, m + 1, e);
    }
  }

  T update(int loc, T val, int node = 0, int s = 0, int e = -1) {
    if (e == -1) e = treeSZ / 2 - 1;
    if (loc < s || e < loc) return tree[node];
    if (s == e) {
      return tree[node] = val % 2 ? 1 : 0;
    }
    int m = ( s + e ) >> 1;
    return tree[node] = update(loc, val, node * 2 + 1, s, m) + update(loc, val, node * 2 + 2, m + 1, e);
  }
};

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;

  segTree<int> sg(v);
  int q;
  cin >> q;
  while (q--) {
    int i, l, r;
    cin >> i >> l >> r;
    if (i == 1)
      sg.update(l - 1, r);
    else {
      l--; r--;
      int ans = sg.query(l, r);
      if (i == 2)
        cout << ( r - l + 1 - ans ) << endl;
      else
        cout << ans << endl;
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
