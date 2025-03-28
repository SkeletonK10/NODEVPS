#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;

//////Union-Find/////////////////////////////////////////////////////////////////////////

struct union_find {
  std::vector<int> arr;
  int compo_size;

  union_find(int sz) {
    arr.resize(sz + 1);
    for (int i = 1; i <= sz; i++)
      arr[i] = i;
    compo_size = sz;
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
      compo_size--;
    }
  }

  int getCompo() { return compo_size; }
};

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll ans[5001], comb[5001][5001];

void preprocess() {
  comb[0][0] = 1;
  for (int i = 1;i <= 5000;i++) {
    comb[i][0] = 1;
    for (int j = 1;j <= i;j++)
      comb[i][j] = ( comb[i - 1][j - 1] + comb[i - 1][j] ) % MOD;
  }

  ans[0] = 1;
  for (int i = 1;i <= 5000;i++)
    for (int j = 0;j < i;j++)
      ans[i] = ( ans[i] + comb[i - 1][j] * ans[i - j - 1] ) % MOD;
}

void solve() {
  preprocess();
  int n, m;
  cin >> n >> m;
  union_find uf(n);
  for (int i = 0;i < m;i++) {
    int s, e;
    cin >> s >> e;
    uf.merge(s, e);
    cout << ans[uf.getCompo()] << endl;
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
