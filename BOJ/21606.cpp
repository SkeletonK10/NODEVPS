#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

ll ans;

ll dfs(int cur, int parent, vector<vector<int>>& adj, string& isIn) {
  vector<ll> acc;
  for (int& nxt : adj[cur])
    if (nxt != parent)
      acc.push_back(dfs(nxt, cur, adj, isIn));

  if (isIn[cur] == '1') {
    for (ll i : acc)
      ans += i;
    return 1;
  }
  else {
    ll s = 0;
    for (ll i : acc) {
      ans += s * i;
      s += i;
    }
    return s;
  }
}

void solve() {
  int n;
  string isIn;
  cin >> n >> isIn;
  isIn = '.' + isIn; // one-base
  vector<vector<int>> adj(n + 1);
  for (int i = 0;i < n - 1;i++) {
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  dfs(1, 0, adj, isIn);

  cout << ans * 2;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
