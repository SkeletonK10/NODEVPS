//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;

//////Constants//////////////////////////////////////////////////////////////////////////

const long long LINF = 987654321987654321LL;

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  N++;
  vector<vector<ll>> adj(N, vector<ll>(N, -LINF));

  for (int i = 0;i < M;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s][e] = max(adj[s][e], (ll)c);
  }

  vector<int> order(N + 1);
  for (int i = 0;i < N;i++)
    order[i] = i;

  ll ans = -1;
  do {
    ll sum = 0;
    for (int i = 0;i < N;i++) {
      int s = order[i];
      int e = order[i + 1];
      sum += adj[s][e];
    }
    ans = max(ans, sum);
  } while (next_permutation(order.begin() + 1, order.end() - 1));

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
