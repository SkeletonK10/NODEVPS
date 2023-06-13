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

ll solve(int N, int K) {
  vector<int> sch[10][10];
  for (int i = 0;i < N;i++) {
    for (int j = 0;j < N;j++) {
      if (i == j) continue;
      int d, temp;
      cin >> d;
      sch[i][j].push_back(d);
      for (int k = 0;k < d;k++) {
        cin >> temp;
        sch[i][j].push_back(temp);
      }
    }
  }

  vector<vector<ll>> ans(K + 1, vector<ll>(N, LINF));
  ans[0][0] = 0;

  for (int i = 0;i < K;i++) {
    for (int j = 0;j < N;j++) {
      for (int k = 0;k < N;k++) {
        if (j == k) continue;
        int period = sch[j][k][0];
        int cost = sch[j][k][i % period + 1];
        if (cost)
          ans[i + 1][k] = min(ans[i + 1][k], ans[i][j] + cost);
      }
    }
  }
  return ans[K][N - 1];
}

int main() {
  FastIO;
  int testcase = 0;
  int N, K;
  while (true) {
    cin >> N >> K;
    if (N == 0 && K == 0)
      break;

    testcase++;
    if (testcase > 1)
      cout << endl;
    cout << "Scenario #" << testcase << endl;

    ll ans = solve(N, K);
    if (ans == LINF)
      cout << "No flight possible." << endl;
    else
      cout << "The best flight costs " << ans << '.' << endl;
  }
}
