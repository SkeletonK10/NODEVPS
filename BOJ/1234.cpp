#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tiii;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

ll comb[101][101];
ll dp[12][101][101][101];

ll safeAccess(int i, int j, int k, int l) {
  if (max({ j, k, l }) > 100) return 0;
  else return dp[i][j][k][l];
}

void computeComb() {
  comb[0][0] = 1;
  for (int n = 1;n <= 100;n++) {
    comb[n][0] = 1;
    for (int r = 1; r <= n;r++)
      comb[n][r] = comb[n - 1][r - 1] + comb[n - 1][r];
  }
    
}

void solve() {
  computeComb();
  int N, R, G, B;
  ll ans = 0;
  cin >> N >> R >> G >> B;
  dp[0][R][G][B] = 1;
  for (int d = 1; d <= N;d++) {
    for (int r = 0;r <= R;r++) {
      for (int g = 0;g <= G;g++) {
        for (int b = 0; b <= B;b++) {
          ll temp1 = 0, temp2 = 0, temp3 = 0;
          temp1 += safeAccess(d - 1, r + d, g, b);
          temp1 += safeAccess(d - 1, r, g + d, b);
          temp1 += safeAccess(d - 1, r, g, b + d);
          if (d % 2 == 0) {
            int h = d / 2;
            temp2 += safeAccess(d - 1, r + h, g + h, b);
            temp2 += safeAccess(d - 1, r + h, g, b + h);
            temp2 += safeAccess(d - 1, r, g + h, b + h);
            temp2 *= comb[d][h];
          }
          if (d % 3 == 0) {
            int t = d / 3;
            temp3 += safeAccess(d - 1, r + t, g + t, b + t);
            temp3 *= comb[d][d - t] * comb[d - t][t];
          }
          dp[d][r][g][b] = temp1 + temp2 + temp3;
          if (d == N)
            ans += dp[d][r][g][b];
        }
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
