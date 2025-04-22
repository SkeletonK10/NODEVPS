#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define FF first
#define SS second

//////New Type Definition////////////////////////////////////////////////////////////////

typedef std::pair<int, int> pii;

//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<pii> v(N);
  for (auto& [a, b] : v)
    cin >> a >> b;
  sort(v.begin(), v.end());
  int mnB = INF;
  int ans = N;
  for (int i = 0;i < N;i++) {
    mnB = min(mnB, v[i].SS);
    if (mnB < v[i].SS)
      ans--;
  }
  cout << ans << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
