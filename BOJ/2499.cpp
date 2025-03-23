#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define all(x) (x).begin(), (x).end()

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

int field[21][21];
int dp[21][40001];
pii prv[21][40001];

void solve() {
  for (int i = 0;i <= 20;i++)
    for (int j = 0;j <= 40000;j++)
      dp[i][j] = INF;
  dp[0][0] = 0;

  int n;
  cin >> n;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= n;j++) {
      cin >> field[i][j];
      field[i][j] += field[i - 1][j];
    }
  }

  for (int i = n;i >= 0;i--) {
    for (int j = 1;j <= n;j++) {
      int up = field[i][j];
      int gap = field[n][j] - ( up * 2 );
      for (int k = 40000;k >= up;k--) {
        if (abs(dp[j][k]) > abs(dp[j - 1][k - up] + gap)) {
          dp[j][k] = dp[j - 1][k - up] + gap;
          prv[j][k] = { up, i };
        }
      }
    }
  }
  int ans = INF, ansI = -1;
  for (int i = 0;i <= 40000;i++) {
    if (abs(dp[n][i]) < ans) {
      ans = abs(dp[n][i]);
      ansI = i;
    }
  }

  cout << ans << endl;
  vector<int> ansV;
  for (int i = n; i >= 1;i--) {
    auto [p, idx] = prv[i][ansI];
    ansI -= p;
    ansV.push_back(n - idx);
  }
  reverse(all(ansV));
  for (int a : ansV)
    cout << a << ' ';
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
