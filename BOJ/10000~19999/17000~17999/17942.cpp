#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

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
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    pq.push({ v[i],i });
  }
    int k;
  cin >> k;
  vector<vector<pii>> adj(n + 1);
  for (int i = 0;i < k;i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({ b,c });
  }
  int ans = 0;
  vector<bool> vst(n + 1, false);
  while (m) {
    auto [study, cur] = pq.top();
    pq.pop();
    if (vst[cur]) continue;
    ans = max(ans, study);
    vst[cur] = true;
    m--;
    for (auto [dst, e] : adj[cur]) {
      if (!vst[dst]) {
        v[dst] -= e;
        pq.push({ v[dst],dst });
      }
    }
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
