#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false); cin.tie(0);

//////Constants//////////////////////////////////////////////////////////////////////////

const int INF = 987654321;
const int SZ = 10;

//////2D Graph Search////////////////////////////////////////////////////////////////////

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int field[SZ][SZ];
int paper[5] = { 5,5,5,5,5 };
int ans = INF;

bool isAll1(int x, int y, int n) {
  if (!inRange(x + n, y + n, SZ, SZ))
    return false;
  for (int i = x;i <= x + n;i++)
    for (int j = y;j <= y + n;j++)
      if (!field[i][j])
        return false;
  return true;
}

void fillSquare(int x, int y, int n, int to) {
  // if (!inRange(x + n, y + n, SZ, SZ))
  //   return false;
  for (int i = x;i <= x + n;i++)
    for (int j = y;j <= y + n;j++)
      field[i][j] = to;
}

void backTrack(int idx, int depth) {
  int x = idx / 10, y = idx % 10;
  if (!field[x][y]) return backTrack(idx + 1, depth);
  if (depth > ans) return;
  if (idx >= 100) {
    ans = min(ans, depth);
    return;
  }


  for (int i = 4;i >= 0;i--) {
    if (paper[i] && isAll1(x, y, i)) {
      paper[i]--;
      // cout << "FILL " << x << ',' << y << " TO " << x + i << ',' << y + i << endl;
      // cout << "PAPER REMAIN: ";
      // for (int a = 0;a < 5;a++)
      //   cout << paper[a] << ' ';
      // cout << endl;
      fillSquare(x, y, i, 0);
      backTrack(idx + 1, depth + 1);
      fillSquare(x, y, i, 1);
      paper[i]++;
    }
  }
}

void solve() {
  // time_t start = clock();
  for (int i = 0;i < 10;i++)
    for (int j = 0;j < 10;j++)
      cin >> field[i][j];
  backTrack(0, 0);
  cout << ( ans == INF ? -1 : ans ) << endl;
  // time_t end = clock();
  // cout << "TIME SPENT: " << end - start << "ms" << endl;
}

int main() {
  FastIO;
  int testcase = 1;
  //cin >> testcase;
  for (int tc = 1;tc <= testcase;tc++) {
    solve();
  }
}
