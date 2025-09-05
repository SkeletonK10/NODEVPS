//////New Type Definition////////////////////////////////////////////////////////////////

#include <vector>
typedef long long ll;
typedef std::pair<int, int> pii;

//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 1987654321;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M, r;
  cin >> N >> M >> r;
  vector<vector<pii>> adj(N + 1);
  for (int i = 0;i < M;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
  }

  queue<int> q;
  vector<int> vst(N + 1, INF);
  q.push(r);
  vst[r] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto [nxt, c] : adj[cur]) {
      if (vst[nxt] == INF)
        q.push(nxt);
      vst[nxt] = min(vst[nxt], c);
    }
  }
  ll ans = 0;
  for (int i = 1;i <= N;i++) {
    if (vst[i] == INF) {
      cout << -1;
      return;
    }
    ans += vst[i];
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
