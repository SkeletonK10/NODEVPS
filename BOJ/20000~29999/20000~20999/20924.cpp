#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int poleCost, branchCost;

pii findPole(vector<vector<pii>>& adj, int cur, int parent) {
  int dgr = 0, nx;
  for (auto& [next, cost] : adj[cur]) {
    if (next == parent) continue;
    dgr++;
    nx = next;
  }
  if (dgr != 1) return { parent,cur };
  return findPole(adj, nx, cur);
}

int findBranch(vector<vector<pii>>& adj, int cur, int parent) {
  int res = 0;
  for (auto& [next, cost] : adj[cur]) {
    if (next == parent) continue;
    res = max(res, cost + findBranch(adj, next, cur));
  }
  return res;
}

void solve() {
  int n, r;
  cin >> n >> r;
  vector<vector<pii>> adj(n + 1);
  for (int i = 0;i < n - 1;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    adj[e].push_back({ s,c });
  }
  auto [parent, pole] = findPole(adj, r, 0);
  int cp = r, pp = 0;
  int cost1 = 0;
  while (cp != pole) {
    int n;
    for (auto& [next, cost] : adj[cp]) {
      if (next == pp) continue;
      cost1 += cost;
      n = next;
    }
    pp = cp;
    cp = n;
  }
  int cost2 = findBranch(adj, pole, parent);
  cout << cost1 << ' ' << cost2;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
