//////2D Graph Search////////////////////////////////////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

//////Custom Preprocessor Directives/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
char field[501][501];

int dfs(int x, int y, int dir, int depth = -1) {
  if (!inRange(x, y, N, N))
    return 0;
  if (depth == -1)
    return dfs(x + dx[dir], y + dy[dir], dir, depth + 1);

  if (field[x][y] == 'W')
    return dfs(x + dx[dir], y + dy[dir], dir, depth + 1);
  if (field[x][y] == 'B')
    return depth;
  return 0;
}

void solve() {
  cin >> N;
  for (int i = 0;i < N;i++)
    cin >> field[i];

  int ans = 0, ansX, ansY;
  for (int i = 0;i < N;i++) {
    for (int j = 0;j < N;j++) {
      if (field[i][j] != '.') continue;
      int temp = 0;
      for (int k = 0;k < 8;k++)
        temp += dfs(i, j, k);
      if (ans < temp) {
        ans = temp;
        ansX = i;
        ansY = j;
      }
    }
  }
  // 순서 주의
  if (ans)
    cout << ansY << ' ' << ansX << endl << ans;
  else
    cout << "PASS";
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
