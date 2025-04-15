#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

//////Constants//////////////////////////////////////////////////////////////////////////

const int MOD = 1e9 + 7;
const int INF = 987654321;
const long long LINF = 987654321987654321LL;
const int SZ = 262144;
const double PI = acos(-1);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int adj[10][10];

void solve() {
  memset(adj, -1, sizeof(adj));
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0;i < n;i++)
    v[i] = i + 1;

  for (int i = 0;i < m;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s][e] = c;
  }

  int ans = INF;
  vector<int> ansV;
  do {
    int tAns = 0;
    for (int i = 0;i < n;i++) {
      int cost = adj[v[i]][v[( i + 1 ) % n]];
      if (cost > 0)
        tAns = max(tAns, cost);
      else
        tAns = INF;
    }
    if (ans > tAns) {
      ans = tAns;
      ansV = v;
    }
  } while (next_permutation(v.begin(), v.end()));
  if (ans == INF) {
    cout << -1;
    return;
  }
  else {
    cout << ans << endl;
    for (int i : ansV)
      cout << i << ' ';
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
