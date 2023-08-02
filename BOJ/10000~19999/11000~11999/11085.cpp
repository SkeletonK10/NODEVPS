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

void solve() {
  int n, m, bj, cv;
  cin >> n >> m >> bj >> cv;
  vector<vector<pii>> adj(n);
  for (int i = 0;i < m;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    adj[e].push_back({ s,c });
  }

  priority_queue<pii> pq;
  vector<int> vst(n);
  vst[bj] = INF;
  pq.push({ INF,bj });
  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    if (cost < vst[cur])
      continue;
    for (auto [next, nCost] : adj[cur]) {
      int nCand = min(nCost, vst[cur]);
      if (vst[next] < nCand) {
        vst[next] = nCand;
        pq.push({ nCand,next });
      }
    }
  }
  cout << vst[cv];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
