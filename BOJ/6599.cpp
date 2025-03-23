#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

int solve(int n) {
  vector<tiii> v(1);
  for (int i = 1;i <= n;i++) {
    vector<int> t(3);
    for (int j = 0;j < 3;j++)
      cin >> t[j];
    sort(all(t));
    v.push_back({ t[0],t[1],t[2] });
    v.push_back({ t[0],t[2],t[1] });
    v.push_back({ t[1],t[2],t[0] });
  }

  int ans = 0;
  vector<vector<int>> dp(3 * n + 1, vector<int>(3 * n + 1));
  for (int i = 1;i <= 3 * n;i++) {
    dp[1][i] = get<2>(v[i]);
    ans = max(ans, dp[1][i]);
  }

  for (int i = 2;i <= 3 * n;i++) {
    for (int j = 1;j <= 3 * n;j++) {
      for (int k = 1;k <= 3 * n;k++) {
        auto [x1, y1, z1] = v[j];
        auto [x2, y2, z2] = v[k];
        if (x1 < x2 && y1 < y2)
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + z1);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;;tc++) {
    int n;
    cin >> n;
    if (!n) break;
    int ans = solve(n);
    cout << "Case " << tc << ": maximum height = " << ans << endl;
  }
}
