#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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

int totalSpent(int n, int m, int startNode, vector<vector<tiii>>& adj, vector<tiii>& edge) {
  int total = 0;
  vector<int> burnt(n + 1, INF), burntEdge(m, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({ 0,startNode });
  burnt[startNode] = 0;
  while (!pq.empty()) {
    auto [time, node] = pq.top();
    pq.pop();
    // cout << time << ' ' << node << endl;
    if (burnt[node] < time)
      continue;
    total = max(total, time);

    for (auto& [next, cost, index] : adj[node]) {
      // Edge for single node
      if (node == next)
        total = max(total, time + cost / 2);
      // Already burning edge
      else if (burntEdge[index] != INF)
        total = max(total, time + ( cost - ( time - burntEdge[index] ) ) / 2);
      else {
        burntEdge[index] = time;
        if (burnt[next] > time + cost) {
          burnt[next] = time + cost;
          pq.push({ time + cost, next });
        }
      }
    }
  }
  return total;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<tiii>> adj(n + 1);
  vector<tiii> edge(m);
  
  for (int i = 0;i < m;i++) {
    int s, e, l;
    cin >> s >> e >> l;
    adj[s].push_back({ e, l * 2, i });
    if (s != e)
      adj[e].push_back({ s, l * 2, i });
    edge.push_back({ s, e, l * 2 });
  }

  int ans = INF;
  for (int i = 1;i <= n;i++) {
    // cout << "-------------CASE " << i << "---------------" << endl;
    ans = min(ans, totalSpent(n, m, i, adj, edge));
  }

  cout << fixed << setprecision(1) << (double)ans / 2;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
