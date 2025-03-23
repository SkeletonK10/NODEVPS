#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
  for (int i = 0;i < m;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s][e] = c;
  }

  int ans = INF;
  for (int k = 1;k <= n;k++) {
    for (int i = 1;i <= n;i++)
      for (int j = 1;j <= n;j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    for (int i = 1;i <= n;i++)
      ans = min(ans, adj[i][i]);
  }
  cout << ( ans == INF ? -1 : ans );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
