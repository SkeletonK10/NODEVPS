#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int treeCnt(int t, int p, vector<vector<int>>& adj, vector<int>& cnt) {
  int cur = 1;
  for (int& next : adj[t]) {
    if (next == p) continue;
    cur += treeCnt(next, t, adj, cnt);
  }
  return cnt[t] = cur;
}

void solve() {
  int n, k, sh, sc;
  cin >> n >> k >> sh >> sc;
  vector<vector<int>> adj(n + 1);
  vector<tiii> edge;

  for (int i = 0;i < n - 1;i++) {
    int b, e, l;
    cin >> b >> e >> l;
    adj[b].push_back(e);
    adj[e].push_back(b);
    edge.push_back({ b,e,l });
  }

  vector<int> cnt(n + 1);
  treeCnt(1, 0, adj, cnt);

  vector<pair<ll, ll>> res;
  for (int i = 0;i < n - 1;i++) {
    auto& [b, e, l] = edge[i];
    ll small = min(cnt[b], cnt[e]);
    res.push_back({ small * ( n - small ) * ( sc - sh ) * l, i + 1 });
  }

  sort(all(res));

  for (int i = 0;i < k;i++)
    cout << res[n - 2 - i].SS << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
