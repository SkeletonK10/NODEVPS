#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> inDegree(N + 1), dst(N + 1, INF);
  vector<vector<pii>> adj(N + 1);
  for (int i = 1;i <= N;i++) {
    int s;
    cin >> s;
    dst[i] = s;
  }
  for (int i = 0;i < C;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    inDegree[e]++;
  }

  queue<int> q;
  for (int i = 1;i <= N;i++)
    if (!inDegree[i])
      q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto [nxt, c] : adj[cur]) {
      dst[nxt] = max(dst[nxt], dst[cur] + c);
      inDegree[nxt]--;
      if (inDegree[nxt] == 0)
        q.push(nxt);
    }
  }
  for (int i = 1;i <= N;i++)
    cout << dst[i] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
