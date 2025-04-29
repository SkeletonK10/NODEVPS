//////New Type Definition////////////////////////////////////////////////////////////////

#include <complex>
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M, S, E;
  cin >> N >> M;
  vector<vector<pii>> adj(N + 1), revAdj(N + 1);
  vector<int> inDegree(N + 1), outDegree(N + 1), dst(N + 1), revDst(N + 1);
  vector<pii> edge;
  for (int i = 0;i < M;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    revAdj[e].push_back({ s,c });
    edge.push_back({ s,e });
    inDegree[e]++;
    outDegree[s]++;
  }
  cin >> S >> E;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto [nxt, d] : adj[cur]) {
      inDegree[nxt]--;
      dst[nxt] = max(dst[nxt], dst[cur] + d);
      if (inDegree[nxt] == 0)
        q.push(nxt);
    }
  }
  int ansDst = dst[E];
  int maxEdge = 0;
  q.push(E);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto [nxt, d] : revAdj[cur]) {
      outDegree[nxt]--;
      revDst[nxt] = max(revDst[nxt], revDst[cur] + d);
      if (revDst[cur] + d + dst[nxt] == ansDst)
        maxEdge++;
      if (outDegree[nxt] == 0)
        q.push(nxt);
    }
  }
  cout << ansDst << endl << maxEdge;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
