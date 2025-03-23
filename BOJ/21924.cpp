#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

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
  ll ans = 0;
  cin >> n >> m;
  vector<tiii> edges(m);
  for (auto& [c, s, e] : edges) {
    cin >> s >> e >> c;
    ans += c;
  }
  sort(all(edges));

  union_find uf(n);
  for (int edge = 0, i = 0;edge < n - 1;i++) {
    if (i >= m) {
      cout << -1;
      return;
    }
    auto [c, s, e] = edges[i];
    if (uf.find(s) != uf.find(e)) {
      ans -= c;
      uf.merge(s, e);
      edge++;
    }
  }
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
