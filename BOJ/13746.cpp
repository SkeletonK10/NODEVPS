#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

//////2D Graph Search//////////////////////////////////////

const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };

bool inRange(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

///////////////////////////////////////////////////////////

using namespace std;

char field[51][51];
bool vst[51][51];

void solve() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0;i < n;i++)
    cin >> field[i];
  queue<pair<int, int>> q;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      if (field[i][j] == 'L' && !vst[i][j]) {
        ans++;
        vst[i][j] = true;
        q.push({ i,j });
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0;k < 4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (
              inRange(nx, ny, n, m) &&
              !vst[nx][ny] &&
              ( field[nx][ny] == 'C' || field[nx][ny] == 'L' )
              ) {
              vst[nx][ny] = true;
              q.push({ nx,ny });
            }
          }
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
