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
const int SZ = 1 << 10;
const double PI = acos(-1);

///////////////////////////////////////////////////////////

using namespace std;

bool dp[101][SZ];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    if (v[i] < 0) v[i] = -v[i];
  }

  dp[0][0] = true;

  for (int i = 0;i < m;i++)
    for (int j = 0;j < SZ;j++)
      if (dp[i][j])
        for (int k = 1;k <= n;k++)
          dp[i + 1][j ^ v[k]] = true;

  int ans = 0;
  for (int i = 0;i < SZ;i++)
    if (dp[m][i]) ans = i;
  cout << ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  while (testcase--) {
    solve();
  }
}
