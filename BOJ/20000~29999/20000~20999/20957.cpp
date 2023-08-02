#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

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

int cnt[2][10001][7];

void preprocess() {
  cnt[0][1][1] = 2; // 1, 8
  cnt[0][1][2] = 2;
  cnt[0][1][3] = 1;
  cnt[0][1][4] = 1;
  cnt[0][1][5] = 1;
  cnt[0][1][6] = 1;

  cnt[1][1][0] = 1;

  for (int i = 2;i <= 10000;i++) {
    for (int j = 0;j <= 9;j++) {
      for (int k = 0;k < 7;k++) {
        if (j % 7) {
          cnt[0][i][( k + j ) % 7] += cnt[0][i - 1][k];
          cnt[0][i][( k + j ) % 7] %= MOD;
        }
        else {
          cnt[1][i][k] += cnt[0][i - 1][k];
          cnt[1][i][k] %= MOD;
        }
        cnt[1][i][( k + j ) % 7] += cnt[1][i - 1][k];
        cnt[1][i][( k + j ) % 7] %= MOD;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  cout << cnt[1][n][0] << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  cin >> testcase;
  preprocess();
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
