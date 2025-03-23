#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define FF first
#define SS second

//////New Type Definition//////////////////////////////////

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;
typedef std::complex<double> cpx;

///////////////////////////////////////////////////////////

using namespace std;

double dist(const pdd& a, const pdd& b) {
  return sqrt(( a.FF - b.FF ) * ( a.FF - b.FF ) + ( a.SS - b.SS ) * ( a.SS - b.SS ));
}

void solve() {
  int n;
  double sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  cin >> n;
  vector<pdd> cannon(n);
  vector<vector<double>> adj(n + 2, vector<double>(n + 2));
  adj[0][n + 1] = adj[n + 1][0] = dist({ sx, sy }, { ex, ey });
  for (auto& [a, b] : cannon)
    cin >> a >> b;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < i;j++) {
      double wDist = dist(cannon[i], cannon[j]);
      double cDist = 10 + abs(50 - wDist);  // 대포 타는 시간 2초 * 5m/s = 10
      adj[i + 1][j + 1] = adj[j + 1][i + 1] = min(wDist, cDist);
    }
  }
  for (int i = 1;i <= n;i++) {
    adj[0][i] = adj[i][0] = dist({ sx, sy }, cannon[i - 1]);
  }
  for (int i = 1;i <= n;i++) {
    double wDist = dist(cannon[i - 1], { ex, ey });
    double cDist = 10 + abs(50 - wDist);
    adj[n + 1][i] = adj[i][n + 1] = min(wDist, cDist);
  }

  for (int k = 0;k < n + 2;k++)
    for (int i = 0;i < n + 2;i++)
      for (int j = 0;j < n + 2;j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

  cout << fixed << setprecision(6) << adj[0][n + 1] / 5;
}
int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
