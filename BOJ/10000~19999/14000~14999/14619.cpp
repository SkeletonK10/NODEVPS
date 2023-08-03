#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

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
  vector<vector<bool>> adj(n + 1, vector<bool>(n + 1));
  vector<vector<int>> dp(501, vector<int>(n + 1, INF));
  for (int i = 1;i <= n;i++)
    cin >> dp[0][i];
  while (m--) {
    int s, e;
    cin >> s >> e;
    adj[s][e] = adj[e][s] = true;
  }

  for (int i = 1;i <= 500;i++)
    for (int j = 1;j <= n;j++)
      for (int k = 1;k <= n;k++)
        if (adj[j][k])
          dp[i][j] = min(dp[i][j], dp[i - 1][k]);

  int q;
  cin >> q;
  while (q--) {
    int a, k;
    cin >> a >> k;
    cout << ( dp[k][a] == INF ? -1 : dp[k][a] ) << endl;
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
