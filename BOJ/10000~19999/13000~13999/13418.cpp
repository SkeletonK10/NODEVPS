#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
  int n, m, mn = 0, mx = 0;
  cin >> n >> m;
  vector<tiii> edge(m + 1);
  for (auto& [c, s, e] : edge) {
    cin >> s >> e >> c;
    c = c ? 0 : 1;
  }
  sort(all(edge));
  union_find uf1(n), uf2(n);
  for (auto& [c, s, e] : edge) {
    if (uf1.find(s) != uf1.find(e)) {
      mn += c;
      uf1.merge(s, e);
    }
  }
  reverse(all(edge));
  for (auto& [c, s, e] : edge) {
    if (uf2.find(s) != uf2.find(e)) {
      mx += c;
      uf2.merge(s, e);
    }
  }

  cout << mx * mx - mn * mn;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
