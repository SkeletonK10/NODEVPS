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

void solve() {
  int N;
  cin >> N;
  vector<int> v(N + 2);
  v[N + 1] = INF;
  for (int i = 1;i <= N;i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  v[0] = v[1];
  v[N + 1] = v[N];

  int ans = 0;
  for (int i = 0;i < N;i++)
    ans = max(ans, v[i + 2] - v[i]);
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
