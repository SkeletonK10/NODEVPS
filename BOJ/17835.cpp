#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<ll, ll> pll;

//////Constants//////////////////////////////////////////////////////////////////////////

const ll LINF = 987654321987654321LL;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<pll>> adj(N + 1);
  for (int i = 0;i < M;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[e].push_back({ s,c });  // inverted
  }
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<ll> dst(N + 1, LINF);
  for (int i = 0;i < K;i++) {
    int interview;
    cin >> interview;
    pq.push({ 0,interview });
    dst[interview] = 0;
  }
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dst[cur] < d) continue;
    for (auto [nxt, c] : adj[cur]) {
      if (dst[nxt] > d + c) {
        dst[nxt] = d + c;
        pq.push({ d + c,nxt });
      }
    }
  }
  ll ans = 0;
  int ansIdx = 0;
  for (int i = 1;i <= N;i++) {
    if (ans < dst[i]) {
      ans = dst[i];
      ansIdx = i;
    }
  }
  cout << ansIdx << endl << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
