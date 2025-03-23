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

void dijkstra(vector<map<int, int>>& adj, vector<int>& t, vector<int>& res) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int& i : t) {
    res[i] = 0;
    pq.push({ 0,i });
  }

  while (!pq.empty()) {
    auto [dist, cur] = pq.top();
    pq.pop();
    if (dist > res[cur])
      continue;
    for (auto [next, cost] : adj[cur]) {
      if (res[cur] + cost < res[next]) {
        pq.push({ res[cur] + cost, next });
        res[next] = res[cur] + cost;
      }
    }
  }
}

void solve() {
  int v, e;
  cin >> v >> e;
  vector<map<int, int>> adj(v + 1);
  for (int i = 0;i < e;i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (adj[a][b])
      adj[a][b] = min(c, adj[a][b]);
    else
      adj[a][b] = c;

    if (adj[b][a])
      adj[b][a] = min(c, adj[b][a]);
    else
      adj[b][a] = c;
  }

  int mn, mc;
  cin >> mn >> mc;
  vector<int> m(mn), mDist(v + 1, INF);
  for (int& i : m)
    cin >> i;
  dijkstra(adj, m, mDist);

  int sn, sc;
  cin >> sn >> sc;
  vector<int> s(sn), sDist(v + 1, INF);
  for (int& i : s)
    cin >> i;
  dijkstra(adj, s, sDist);

  int ans = INF;
  for (int i = 1;i <= v;i++) {
    if (0 < mDist[i] && mDist[i] <= mc && 0 < sDist[i] && sDist[i] <= sc)
      ans = min(ans, mDist[i] + sDist[i]);
  }
  cout << ( ( ans == INF ) ? -1 : ans );
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
