#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const ll LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& depth, vector<int>& subTreeNodes, int cur) {
  // cout << "START " << cur << endl;
  int nodes = 1;
  for (int& nxt : adj[cur]) {
    // cout << nxt << endl;
    if (depth[nxt] == -1) {
      depth[nxt] = depth[cur] + 1;
      nodes += dfs(adj, depth, subTreeNodes, nxt);
    }
  }
  // cout << "END " << cur << " - TOTAL NODE: " << nodes << endl;
  return subTreeNodes[cur] = nodes;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<pii> edge;
  vector<ll> usage;
  for (int i = 0;i < n - 1;i++) {
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
    edge.push_back({ s,e });
  }
  vector<int> depth(n + 1, -1), subTreeNodes(n + 1, 0);
  depth[1] = 0;
  dfs(adj, depth, subTreeNodes, 1);
  for (auto [s, e] : edge) {
    if (depth[s] > depth[e])
      swap(s, e);
    usage.push_back((ll)subTreeNodes[e] * ( n - subTreeNodes[e] ));
  }
  sort(all(usage));
  vector<int> w(n - 1);
  for (int& i : w)
    cin >> i;
  sort(all(w));
  reverse(all(w));
  ll ans = 0;
  for (int i = 0;i < n - 1;i++) {
    int temp = ( ( usage[i] % MOD ) * w[i] ) % MOD;
    ans = ( ans + temp ) % MOD;
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
