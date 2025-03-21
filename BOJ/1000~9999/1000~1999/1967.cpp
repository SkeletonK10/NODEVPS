#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

//////New Type Definition////////////////////////////////////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int furthest(vector<vector<pii>>& adj, vector<int>& prev, vector<int>& dst, int start) {
  int mxDst = 0, ans = 0;
  stack<int> st;
  st.push(start);
  prev[start] = 0;
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    if (dst[cur] > mxDst) {
      mxDst = dst[cur];
      ans = cur;
    }
    for (auto [nxt, d] : adj[cur]) {
      if (prev[nxt] == -1) {
        st.push(nxt);
        prev[nxt] = cur;
        dst[nxt] = dst[cur] + d;
      }
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<pii>> adj(n + 1);
  for (int i = 0;i < n - 1;i++) {
    int s, e, c;
    cin >> s >> e >> c;
    adj[s].push_back({ e,c });
    adj[e].push_back({ s,c });
  }

  vector<int> prev(n + 1, -1), dst(n + 1);
  int d1 = furthest(adj, prev, dst, 1); // prev & dst: dummy
  fill(all(prev), -1);
  fill(all(dst), 0);
  int d2 = furthest(adj, prev, dst, d1);

  cout << dst[d2];
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
