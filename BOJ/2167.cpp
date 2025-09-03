//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v(N + 1, vector<int>(M + 1));
  for (int i = 1;i <= N;i++) {
    for (int j = 1;j <= M;j++) {
      cin >> v[i][j];
      v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
    }
  }
  int K;
  cin >> K;
  while (K--) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    cout << v[x][y] - v[i - 1][y] - v[x][j - 1] + v[i - 1][j - 1] << endl;
  }
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
