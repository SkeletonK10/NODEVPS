#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll dfs(int cur, int parent, ll dst, vector<vector<pair<int, ll>>>& adj, vector<ll>& campus) {
  ll mx = dst - campus[cur];
  for (auto& [nxt, d] : adj[cur])
    if (nxt != parent)
      mx = max(mx, dfs(nxt, cur, dst + d, adj, campus));
  return mx;
}

void solve() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll> campus(n + 1);
  vector<vector<pair<int, ll>>> adj(n + 1);
  for (ll& i : campus)
    cin >> i;
  for (int i = 0;i < n;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    adj[e].push_back({ s,c });
    ans += 2 * c;
  }
  ans -= dfs(0, -1, 0, adj, campus);
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
